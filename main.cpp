// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT3L
// Names: YAP WENG HONG | TAN FU SHUN | TENG WEI JOE
// IDs: 1211103023 | 1211101407 | 1211102797
// Emails: 1211103023@student.mmu.edu.my | 1211101407@student.mmu.edu.my | 1211102797@student.mmu.edu.my
// Phones: 011-37841415 | 016-3308915 | 017-3300623
// *********************************************************

#include <iostream>
#include <vector>
#include <time.h>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>
#include <numeric>
#include <climits>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

class Character
{
public:
    class Alien
    {
    private:
        vector<int> alienLife{100}; // Original life of the alien.
        vector<int> alienAttack{0}; // Original attack of the alien.

    public:
        void setLife(int life) { alienLife.push_back(life); }  // Set another life using pushback.
        void clearLife() { alienLife.clear(); }                // Clear every life in the alienLife.
        int getLife(int index) { return alienLife.at(index); } // Get life at the specified index.
        int sizeLife() { return alienLife.size(); }            // Return the size of the vector.

        void setAttack(int attack) { alienAttack.push_back(attack); }                            // Set another attack using pushback.
        int getAttack(int index) { return alienAttack.at(index); }                               // Get attack at the specified index.
        int sizeAttack() { return alienAttack.size(); }                                          // Return the size of the vector.
        int accumulateAttack() { return accumulate(alienAttack.begin(), alienAttack.end(), 0); } // Return the accumulation of the attacks in the alien attack.
        void clearAttack() { alienAttack.clear(); }                                              // Clear every attack in the alienLife.
    };

    class Zombie
    {
    private:
        vector<int> zombieNo{};     // The number of the zombies.
        vector<int> zombieLife{};   // The life of the zombies.
        vector<int> zombieAttack{}; // The attack of the zombies.
        vector<int> zombieRange{};  // The range of the zombies.

    public:
        void setZombie(int zombieID) { zombieNo.push_back(zombieID); } // Set a new zombie.
        int getZombie(int index) { return zombieNo.at(index); }        // Return the zombie ID.
        int sizeZombie() { return zombieNo.size(); }                   // Return the number of the zombies.

        void setLife(int life) { zombieLife.push_back(life); }                                                    // Set another life using pushback.
        int getLife(int index) { return zombieLife.at(index); }                                                   // Get life at the specified index.
        void insertLife(int newLife, int position) { zombieLife.insert(zombieLife.begin() + position, newLife); } // Set new life for selected zombie.
        void eraseLife(int position) { zombieLife.erase(zombieLife.begin() + position); }                         // Clear life for selected zombie.
        int sizeLife() { return zombieLife.size(); };                                                             // Return the size of the vector.
        int accumulateZombieLife() { return accumulate(zombieLife.begin(), zombieLife.end(), 0); }                // return the accumulation of the attacks in the alien attack.

        void setAttack(int attack) { zombieAttack.push_back(attack); } // Set another attack using pushback.
        int getAttack(int index) { return zombieAttack.at(index); }    // Get attack at the specified index.
        int sizeAttack() { return zombieAttack.size(); }               // Return the size of the vector.

        void setRange(int range) { zombieRange.push_back(range); } // Set another range using pushback.
        int getRange(int index) { return zombieRange.at(index); }  // Get range at the specified index.
        int sizeRange() { return zombieRange.size(); }             // Return the size of the vector.
    };
};

void gametitle(int &row, int &column) // gametitle
{
    if (column < 11)
    {
        cout << ".: Alien vs Zombie :." << endl;
    }
    else
    {
        int b = 1;
        int c = (column / 2) - 1;
        cout << setw(c) << left << " "
             << setw(b) << left << ".: Alien vs Zombie :." << endl;
    }
}

int changegamesettings(int &row, int &column, int &zombie) // change game settings
{
    system("CLS");
    cout << "Board Settings" << endl;
    cout << "--------------" << endl;
    int a;

    // customise row
    do
    {
        a = false;
        cout << "Enter Rows => ";
        cin >> row;
        if (row < 3) // make sure that alien can put into center of the gameboard
        {
            cout << "Please enter an odd integer number that more than 2" << endl;
            a = true;
            cin.clear();  // clear wrong input
            cin.ignore(); // ignore wrong input
        }
        else if (row % 2 == 0) // make sure that the number cannot be even
        {
            cout << "Please enter an odd integer number that more than 2" << endl;
            a = 1;
            cin.clear();
            cin.ignore();
        }
        else if (cin.fail()) // checking invalid value
        {
            cout << "Please enter an odd integer number that more than 2" << endl;
            a = 1;
            cin.clear();
            cin.ignore();
        }
    } while (a == 1);

    // customise column
    do
    {
        a = false;
        cout << "Enter Columns => ";
        cin >> column;
        if (column < 3)
        {
            cout << "Please enter an odd integer number that more than 2" << endl;
            a = true;
            cin.clear();
            cin.ignore();
        }
        else if (column % 2 == 0)
        {
            cout << "Please enter an odd integer number that more than 2" << endl;
            a = 1;
            cin.clear();
            cin.ignore();
        }
        else if (cin.fail())
        {
            cout << "Please enter an odd integer number that more than 2" << endl;
            a = 1;
            cin.clear();
            cin.ignore();
        }
    } while (a == 1);

    // customise number of zombies
    cout << endl;
    cout << "Zombie Settings" << endl;
    cout << "---------------" << endl;
    do
    {
        a = false;
        cout << "Enter number of Zombies => ";
        cin >> zombie;
        if (zombie < 1)
        {
            cout << "Please enter an integer number that more than 0 and less than 10" << endl;
            a = true;
            cin.clear();
            cin.ignore();
        }
        else if (zombie > 9) // as more than 10 the game become unbalanced
        {
            cout << "Please enter an number that more than 0 and less than 10" << endl;
            a = 1;
            cin.clear();
            cin.ignore();
        }
        else if (cin.fail())
        {
            cout << "Please enter an number that more than 0 and less than 10" << endl;
            a = 1;
            cin.clear();
            cin.ignore();
        }
    } while (a == 1);

    cout << endl;
    cout << "Settings Updated !" << endl;
    system("Pause");
    return row, column, zombie;
}

void defaultgamesettings(int &row, int &column, int &zombie) // default game settings
{
    cout << "Default Game Settings" << endl;
    cout << "---------------------" << endl;
    cout << "Board Rows    :  " << row << endl;
    cout << "Board Columns :  " << column << endl;
    cout << "Zombie Count  :  " << zombie << endl;
    bool YesNo = false;
    while (YesNo = true)
    {
        string wish;
        cout << endl;
        cout << "Do you wish to change the game settings (y/n)? => ";
        cin >> wish;
        if (wish == "n" || wish == "N")
        {
            return;
        }
        else if (wish == "y" || wish == "Y")
        {
            changegamesettings(row, column, zombie);
            return;
        }
        else
        {
            cout << "Just enter y or n only." << endl;
        }
    }
}

void displaydata(Character::Alien aliens, Character::Zombie zombies, int zombie) // display data of each characters
{
    cout << endl;
    int zombiesNum;
    cout << "Alien\t : Life ";
    cout << setw(5) << aliens.getLife(0);
    cout << "  Attack ";
    cout << setw(5) << aliens.getAttack(0);
    cout << endl;
    for (zombiesNum = 0; zombiesNum < zombie; ++zombiesNum)
    {
        cout << "Zombie " << zombiesNum + 1 << " : Life ";
        cout << setw(5) << zombies.getLife(zombiesNum);
        cout << "  Attack ";
        cout << setw(5) << zombies.getAttack(zombiesNum);
        cout << "  Range ";
        cout << setw(5) << zombies.getRange(zombiesNum);
        cout << endl;
    }
    cout << endl;
}

void displayborder(Character::Alien aliens, Character::Zombie zombies, string **arr, int &row, int &column, int &zombie)
{
    system("CLS");
    gametitle(row, column);
    for (int i = 0; i < row; ++i) // for each row
    {
        cout << " ";
        for (int j = 0; j < column; ++j) // display upper border of the row
        {
            cout << "+-";
        }
        cout << "+-" << endl;

        cout << setw(2) << (1 + i); // display row number

        for (int j = 0; j < column; ++j) // display cell content and border of each column
        {
            cout << "|" << arr[i][j];
        }
        cout << "|" << endl;
    }
    cout << " ";
    for (int j = 0; j < column; ++j) // display lower border of the last row
    {
        cout << "+-";
    }
    cout << "+-" << endl;

    cout << "  ";
    for (int j = 0; j < column; ++j) // display column number
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << "  ";
    for (int j = 0; j < column; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl;
    displaydata(aliens, zombies, zombie);
}

int randomLife() // Randomize zombie life.
{
    int life[4] = {100, 150, 200, 250};
    int finalLife = life[rand() % 4];
    return finalLife;
}

int randomAttack() // Randomize zombie attack.
{
    int finalAttack;
    int attack[5] = {10, 15, 20, 25, 30};
    finalAttack = attack[rand() % 5];
    return finalAttack;
}

int randomRange(int &row, int &column) // Randomize zombie range.
{
    int finalRange;
    int range[3] = {1, 2, 3};
    finalRange = range[rand() % 3];
    return finalRange;
}

void assignZombie(int &row, int &column, int &zombie, string **arr, int **PositionZombie) // Generate zombies for the board.
{
    int numberofzombie = 1;
    int randomRow, randomColumn;
    for (int i = 0; i < zombie; ++i)
    {
        // make sure the alien and zombies are not replaced by other zombies.
        do
        {
            randomRow = rand() % row;
            randomColumn = rand() % column;
        } while (arr[randomRow][randomColumn] == "A" || arr[randomRow][randomColumn] == "1" || arr[randomRow][randomColumn] == "2" || arr[randomRow][randomColumn] == "3" || arr[randomRow][randomColumn] == "4" || arr[randomRow][randomColumn] == "5" || arr[randomRow][randomColumn] == "6" || arr[randomRow][randomColumn] == "7" || arr[randomRow][randomColumn] == "8" || arr[randomRow][randomColumn] == "9");

        string Zombienumber = to_string(numberofzombie);
        arr[randomRow][randomColumn] = Zombienumber;
        PositionZombie[i][0] = randomRow; // Assign the Row and Column of each zombie in the array.
        PositionZombie[i][1] = randomColumn;
        numberofzombie = numberofzombie + 1;
    }
}

void generateZombie(Character::Zombie &zombies, int &zombie, int &row, int &column, string **arr, int **PositionZombie) // Generate zombies with random life, attack and range.
{
    for (int i = 0; i < zombie; ++i)
    {
        zombies.setZombie(i);
        int zombieLife = randomLife();
        zombies.setLife(zombieLife);
        int zombieAttack = randomAttack();
        zombies.setAttack(zombieAttack);
        int zombieRange = randomRange(row, column);
        zombies.setRange(zombieRange);
    }
    assignZombie(row, column, zombie, arr, PositionZombie);
}

int **ZombiePosition(int &zombie) // Store position of every zombie.
{
    int **PositionZombie = new int *[zombie];
    for (int i = 0; i < zombie; i++)
    {
        PositionZombie[i] = new int[2];
    }
    return PositionZombie;
}

string **generate2DArr(int &row, int &column) // Initialize 2D array.
{
    string **arr = new string *[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new string[column];
    }
    return arr;
}

string randomObject() // Randomize object.
{
    string finalObject;
    string object[8] = {"^", "v", "<", ">", "h", "p", "r", " "};
    finalObject = object[rand() % 8];
    return finalObject;
}

void putRandom(string **arr, int &row, int &column) // Put the game object randomly in the game board.
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            arr[i][j] = randomObject();
        }
    }
}

void spawnfromtrail(string **arr, int &row, int &column, int &zombie, int &rowStart, Character::Alien aliens, Character::Zombie zombies) // Trail change to others object randomly after alien's turn.
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            if (arr[i][j] == ".")
            {
                arr[i][j] = randomObject();
            }
        }
    }
    cout << "Alien's turn ends. The trail is reset." << endl;
    cout << endl;
}

string randomRock() // Randomize object when hit the rock.
{
    string finalRock;
    string rock[7] = {"^", "v", "<", ">", "h", "p", " "};
    finalRock = rock[rand() % 7];
    return finalRock;
}

string typeCommand(string &command) // Type command to operate.
{
    cout << "command > ";
    cin >> command;
    cout << endl;
    return command;
}

void help() // Show command list.
{
    cout << "1. up\t\t- Move Up" << endl;
    cout << "2. down\t\t- Move Down" << endl;
    cout << "3. left\t\t- Move Left " << endl;
    cout << "4. right\t- Move Right" << endl;
    cout << "5. arrow\t- Change the direction of an arrow" << endl;
    cout << "6. help\t\t- Display the valid commands" << endl;
    cout << "7. save\t\t- Save the game " << endl;
    cout << "8. load\t\t- Load previous saved game" << endl;
    cout << "9. quit\t\t- Quit the game" << endl;
    return;
}

void resetAlienAttack(Character::Alien &aliens) // Reset alien attack to zero.
{
    aliens.clearAttack();
    aliens.setAttack(0);
}

void alienAttackIncrease(Character::Alien &aliens) // Allow alien attack to stacking damage.
{
    int sum;
    aliens.setAttack(20);
    sum = aliens.accumulateAttack();
    aliens.clearAttack();
    aliens.setAttack(sum);
}

void changeArrow(string **arr, int row, int column) // Change the direction of the arrow.
{
    int x;
    int y;
    string newarrow;
    int error;
    do
    {
        error = 0;
        cout << "Enter row, column and direction : ";
        cin >> x >> y >> newarrow;
        if (x == cin.fail() || y == cin.fail()) // Check invalid coordinate.
        {
            cout << "Please enter a valid coordinate." << endl;
            error = 1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (x > row || x < 1 || y > column || y < 1) // Check invalid coordinate.
        {
            cout << "Please enter a valid coordinate." << endl;
            error = 1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (arr[x - 1][y - 1] != "^" && arr[x - 1][y - 1] != "v" && arr[x - 1][y - 1] != "<" && arr[x - 1][y - 1] != ">") // Check invalid coordinate.
        {
            cout << "Please enter a valid coordinate." << endl;
            error = 1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (newarrow != "up" && newarrow != "down" && newarrow != "left" && newarrow != "right" || newarrow == "left" && arr[x - 1][y - 1] == "<" || newarrow == "right" && arr[x - 1][y - 1] == ">" || newarrow == "up" && arr[x - 1][y - 1] == "^" || newarrow == "down" && arr[x - 1][y - 1] == "v") // Check invalid direction.
        {

            cout << "Please enter a valid direction or new direction." << endl;
            error = 1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (error == 1);
    if (newarrow == "up")
    {
        newarrow = "^";
    }
    else if (newarrow == "down")
    {
        newarrow = "v";
    }
    else if (newarrow == "left")
    {
        newarrow = "<";
    }
    else if (newarrow == "right")
    {
        newarrow = ">";
    }
    string z = arr[x - 1][y - 1];
    arr[x - 1][y - 1] = newarrow;
    cout << "Arrow " << z << " is switched to " << newarrow << "." << endl;
    cout << endl;
    system("PAUSE");
}

string moveUp(int &x, int &y, string **arr, string &hit, Character::Zombie zombies) // Action for alien to move up.
{
    if (x - 1 >= 0)
    {
        bool move = true;
        for (int i = 1; i <= zombies.sizeZombie(); i++)
        {
            if (arr[x - 1][y] == to_string(i))
            {
                move = false;
                hit = to_string(i);
            }
            else
            {
                continue;
            }
        }
        if (move == true)
        {
            arr[x][y] = ".";
            x = x - 1;
            hit = arr[x][y];
            arr[x][y] = "A";
        }
    }
    return hit;
}

string moveDown(int &x, int &y, string **arr, string &hit, int &row, Character::Zombie zombies) // Action for alien to move down.
{
    if (x + 1 < row)
    {
        bool move = true;
        for (int i = 1; i <= zombies.sizeZombie(); i++)
        {
            if (arr[x + 1][y] == to_string(i))
            {
                move = false;
                hit = to_string(i);
            }
            else
            {
                continue;
            }
        }
        if (move == true)
        {
            arr[x][y] = ".";
            x = x + 1;
            hit = arr[x][y];
            arr[x][y] = "A";
        }
    }
    return hit;
}

string moveLeft(int &x, int &y, string **arr, string &hit, Character::Zombie zombies) // Action for alien to move left.
{
    if (y - 1 >= 0)
    {
        bool move = true;
        for (int i = 1; i <= zombies.sizeZombie(); i++)
        {
            if (arr[x][y - 1] == to_string(i))
            {
                move = false;
                hit = to_string(i);
            }
            else
            {
                continue;
            }
        }
        if (move == true)
        {
            arr[x][y] = ".";
            y = y - 1;
            hit = arr[x][y];
            arr[x][y] = "A";
        }
    }
    return hit;
}

string moveRight(int &x, int &y, string **arr, string &hit, int &column, Character::Zombie zombies) // Action for alien to move right.
{
    if (y + 1 < column)
    {
        bool move = true;
        for (int i = 1; i <= zombies.sizeZombie(); i++)
        {
            if (arr[x][y + 1] == to_string(i))
            {
                move = false;
                hit = to_string(i);
            }
            else
            {
                continue;
            }
        }
        if (move == true)
        {
            arr[x][y] = ".";
            y = y + 1;
            hit = arr[x][y];
            arr[x][y] = "A";
        }
    }
    return hit;
}

string continuousMove(string &hit, string &lastMove, int &x, int &y, string **arr, int &row, int &column, Character::Zombie zombies) // Identify what is the next hit.
{
    if (lastMove == "^")
    {
        hit = moveUp(x, y, arr, hit, zombies);
    }
    else if (lastMove == "v")
    {
        hit = moveDown(x, y, arr, hit, row, zombies);
    }
    else if (lastMove == "<")
    {
        hit = moveLeft(x, y, arr, hit, zombies);
    }
    else if (lastMove == ">")
    {
        hit = moveRight(x, y, arr, hit, column, zombies);
    }
    return hit;
}

string findClosestZombie(int &row, int &column, string **arr, int **PositionZombie, int zombie, Character::Zombie &zombies) // A calculater for finding the shortest distance between the alien and a zombie.
{
    int rowA, colA;
    int shortestDistance = INT_MAX; // Initialize shortestDistance to a large number.
    string shortestPoint = "0";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (arr[i][j] == "A")
            {
                rowA = i;
                colA = j;
            }
        }
    }
    if (zombies.accumulateZombieLife() == 0)
    {
    }
    vector<string> sameDistanceZombies;
    for (int i = 0; i < (row); ++i)
    {
        for (int j = 0; j < (column); ++j)
        {
            if (arr[i][j] != "A" && arr[i][j] != "^" && arr[i][j] != "v" && arr[i][j] != "<" && arr[i][j] != ">" && arr[i][j] != "h" && arr[i][j] != "p" && arr[i][j] != "r" && arr[i][j] != " " && arr[i][j] != ".")
            {
                int rowX = i;
                int colX = j;
                int manhattanDistance = abs(rowA - rowX) + abs(colA - colX);
                if (manhattanDistance < shortestDistance)
                {
                    shortestDistance = manhattanDistance;
                    shortestPoint = arr[i][j];
                    sameDistanceZombies.clear();
                    sameDistanceZombies.push_back(arr[i][j]);
                }
                else if (manhattanDistance == shortestDistance)
                {
                    sameDistanceZombies.push_back(arr[i][j]);
                }
            }
        }
    }
    if (sameDistanceZombies.size() > 1)
    {
        // Generate a random number using rand() function.
        int randomIndex = rand() % sameDistanceZombies.size();
        // Access the random element in the vector.
        shortestPoint = sameDistanceZombies[randomIndex];
    }
    return shortestPoint;
}

void alienAttack(Character::Zombie &zombies, Character::Alien &aliens, string &hitZombie, int **PositionZombie, string **arr, int &x, int &y, string &lastMove, int &row, int &column, string &hit, int &zombie) // Allow alien to attack zombie by direct hit.
{
    int zombieNo = stoi(hitZombie);
    int attack = aliens.getAttack(0);
    cout << "Zombie " << zombieNo << " received a damage of " << attack << "." << endl;
    if (attack >= zombies.getLife(zombieNo - 1))
    {
        zombies.eraseLife(zombieNo - 1);
        zombies.insertLife(0, zombieNo - 1);
        arr[PositionZombie[zombieNo - 1][0]][PositionZombie[zombieNo - 1][1]] = " "; // Replace the zombie's position with alien
        cout << "Zombie " << hit << " is defeated." << endl;
        hit = continuousMove(hit, lastMove, x, y, arr, row, column, zombies);
    }
    else
    {
        int life = zombies.getLife(zombieNo - 1) - attack;
        zombies.eraseLife(zombieNo - 1);
        zombies.insertLife(life, zombieNo - 1);
        cout << "Zombie " << zombieNo << " survived the attack." << endl;
        lastMove = hitZombie;
    }
    cout << endl;
}

void hitRock(string &hit, Character::Alien &aliens, Character::Zombie &zombies, string &lastMove, int &row, int &column, string **arr, int &x, int &y, int **PositionZombie, int &zombie) // Display different outputs based on what it hits.
{
    string hitZombie = "0";
    for (int i = 1; i <= zombies.sizeZombie(); i++)
    {
        if (hit == to_string(i))
        {
            hitZombie = to_string(i);
        }
    }
    if (hit == "^")
    {
        cout << "Alien finds an arrow." << endl;
        cout << "Alien's attack is increased by 20." << endl;
        alienAttackIncrease(aliens);
        cout << endl;
        lastMove = "^";
    }
    else if (hit == "v")
    {
        cout << "Alien finds an arrow." << endl;
        cout << "Alien's attack is increased by 20." << endl;
        alienAttackIncrease(aliens);
        cout << endl;
        lastMove = "v";
    }
    else if (hit == "<")
    {
        cout << "Alien finds an arrow." << endl;
        cout << "Alien's attack is increased by 20." << endl;
        alienAttackIncrease(aliens);
        cout << endl;
        lastMove = "<";
    }
    else if (hit == ">")
    {
        cout << "Alien finds an arrow." << endl;
        cout << "Alien's attack is increased by 20." << endl;
        alienAttackIncrease(aliens);
        cout << endl;
        lastMove = ">";
    }
    else if (hit == "h")
    {
        cout << "Alien finds a health pack." << endl;
        cout << "Alien's life is increased by 20." << endl;
        cout << endl;
        aliens.setLife(20);
        int totalLife = aliens.getLife(0) + aliens.getLife(1);
        aliens.clearLife();
        if (totalLife > 100)
        {
            totalLife = 100;
            cout << "Alien's life is full" << endl;
        }
        aliens.setLife(totalLife);
    }
    else if (hit == "p")
    {
        cout << "Alien found a pod!" << endl;
        int closestZombie = stoi(findClosestZombie(row, column, arr, PositionZombie, zombie, zombies));
        if (closestZombie != 0)
        {
            int closestZombieLife = zombies.getLife(closestZombie - 1) - 10;
            if (closestZombieLife <= 0)
            {
                arr[PositionZombie[closestZombie - 1][0]][PositionZombie[closestZombie - 1][1]] = " ";
                closestZombieLife = 0;
            }
            zombies.eraseLife(closestZombie - 1);
            zombies.insertLife(closestZombieLife, (closestZombie - 1));
            cout << "Zombie " << zombies.getZombie(closestZombie - 1) + 1 << " receives a damage of 10." << endl;
            cout << endl;
        }
    }
    else if (hit == "r")
    {
        string objectRock = randomRock();
        string objectBeneathRock;
        if (objectRock == "h")
        {
            objectBeneathRock = "a health pack";
            resetAlienAttack(aliens);
        }
        else if (objectRock == "p")
        {
            objectBeneathRock = "a pod";
            resetAlienAttack(aliens);
        }
        else if (objectRock == " ")
        {
            objectBeneathRock = "nothing";
            resetAlienAttack(aliens);
        }
        else if (objectRock == "^")
        {
            objectBeneathRock = "an arrow ^";
            resetAlienAttack(aliens);
        }
        else if (objectRock == "v")
        {
            objectBeneathRock = "an arrow v";
            resetAlienAttack(aliens);
        }
        else if (objectRock == "<")
        {
            objectBeneathRock = "an arrow <";
            resetAlienAttack(aliens);
        }
        else if (objectRock == ">")
        {
            objectBeneathRock = "an arrow >";
        }
        cout << "Alien stumbles upon a rock." << endl;
        cout << "Alien discovers " << objectBeneathRock << " beneath the rock." << endl;
        cout << endl;
        arr[x][y] = objectRock;
        if (lastMove == "^")
        {
            x = x + 1;
            arr[x][y] = "A";
        }
        else if (lastMove == "v")
        {
            x = x - 1;
            arr[x][y] = "A";
        }
        if (lastMove == "<")
        {
            y = y + 1;
            arr[x][y] = "A";
        }
        if (lastMove == ">")
        {
            y = y - 1;
            arr[x][y] = "A";
        }
    }
    else if (hit == " ")
    {
        cout << "Alien finds an empty space." << endl;
        cout << endl;
    }
    else if (hit == ".")
    {
        cout << "Alien finds an empty space." << endl;
        cout << endl;
    }
    else if (hit == hitZombie)
    {
        alienAttack(zombies, aliens, hitZombie, PositionZombie, arr, x, y, lastMove, row, column, hit, zombie);
    }
    else if (hit == "")
    {
        cout << "Alien is unable to move" << endl;
        cout << endl;
    }
}

void zombieAttack(Character::Zombie &zombies, Character::Alien &aliens, int **PositionZombie, int i, string **arr, int &row, int &column) // Zombie detect and attack alien if nearby.
{
    bool attack = false;
    for (int a = 1; a <= zombies.getRange(i); a++)
    {
        if (PositionZombie[i][0] - a >= 0 && arr[PositionZombie[i][0] - a][PositionZombie[i][1]] == "A")
        { // To prevent oversize and detect upper position.
            attack = true;
            break;
        }
        if (PositionZombie[i][0] + a <= row - 1 && arr[PositionZombie[i][0] + a][PositionZombie[i][1]] == "A")
        { // To prevent oversize and detect lower position.
            attack = true;
            break;
        }
        if (PositionZombie[i][1] + a <= column - 1 && arr[PositionZombie[i][0]][PositionZombie[i][1] + a] == "A")
        { // To prevent oversize and detect right position.
            attack = true;
            break;
        }
        if (PositionZombie[i][1] - a >= 0 && arr[PositionZombie[i][0]][PositionZombie[i][1] - a] == "A")
        { // To prevent oversize and detect left position.
            attack = true;
            break;
        }
        for (int b = 0; b <= zombies.getRange(i) - a; b++)
        {
            if (PositionZombie[i][1] + b <= column - 1 && PositionZombie[i][0] - a >= 0 && arr[PositionZombie[i][0] - a][PositionZombie[i][1] + b] == "A")
            { // To detect upper right diagonal position.
                attack = true;
                break;
            }
            if (PositionZombie[i][1] - b >= 0 && PositionZombie[i][0] - a >= 0 && arr[PositionZombie[i][0] - a][PositionZombie[i][1] - b] == "A")
            { // To detect upper left diagonal position.
                attack = true;
                break;
            }
            if (PositionZombie[i][1] + b <= column - 1 && PositionZombie[i][0] + a <= row - 1 && arr[PositionZombie[i][0] + a][PositionZombie[i][1] + b] == "A")
            { // To detect lower right diagonal position.
                attack = true;
                break;
            }
            if (PositionZombie[i][1] - b >= 0 && PositionZombie[i][0] + a <= row - 1 && arr[PositionZombie[i][0] + a][PositionZombie[i][1] - b] == "A")
            { // To detect lower left diagonal position.
                attack = true;
                break;
            }
        }
    }

    if (attack == false)
    {
        cout << "Zombie " << i + 1 << " is unable to attack alien." << endl;
        cout << "Alien is too far away." << endl;
    }
    else if (attack == true)
    {
        cout << "Zombie " << i + 1 << " attacks Alien." << endl;
        cout << "Alien receives a damage of " << zombies.getAttack(i) << "." << endl;
        aliens.setLife(zombies.getAttack(i));
        int totalLife = aliens.getLife(0) - aliens.getLife(1);
        aliens.clearLife();
        if (totalLife < 0)
        {
            totalLife = 0;
        }
        aliens.setLife(totalLife);
    }
}

void zombieMove(Character::Zombie &zombies, Character::Alien &aliens, int &row, int &column, string **arr, int **PositionZombie, int &rowStart, int &zombie) // Action for zombie to move.
{
    resetAlienAttack(aliens);
    rowStart = 0;
    system("CLS");
    displayborder(aliens, zombies, arr, row, column, zombie);
    for (int i = 0; i < zombie; i++)
    {
        if (zombies.getLife(i) == 0)
        {
            arr[PositionZombie[i][0]][PositionZombie[i][1]] = " ";
            continue;
        }
        string direction[4] = {"left", "right", "up", "down"};
        string move = direction[rand() % 4];
        bool hitZombie = false;
        rowStart = 0;
        cout << "Zombie " << i + 1 << "'s turn." << endl;
        if (move == "up")
        { // Movement depend on direcction move.
            cout << "Zombie " << i + 1 << " moves up." << endl;
            if (PositionZombie[i][0] > 0 && arr[PositionZombie[i][0] - 1][PositionZombie[i][1]] != "A" && arr[PositionZombie[i][0] - 1][PositionZombie[i][1]] != "r") // Prevent hit the border, the alien and the rock.
            {
                for (int j = 1; j <= zombies.sizeZombie(); j++)
                {
                    if (arr[PositionZombie[i][0] - 1][PositionZombie[i][1]] == to_string(j))
                    {
                        hitZombie = true;
                    }
                }
                if (hitZombie == false)
                {
                    arr[PositionZombie[i][0]][PositionZombie[i][1]] = " "; // Change the original zombie's position into empty.
                    PositionZombie[i][0] = PositionZombie[i][0] - 1;
                    arr[PositionZombie[i][0]][PositionZombie[i][1]] = to_string(i + 1); // Place the zombie in the new position.
                }
            }
        }
        else if (move == "down")
        {
            cout << "Zombie " << i + 1 << " moves down." << endl;
            if (PositionZombie[i][0] < row - 1 && arr[PositionZombie[i][0] + 1][PositionZombie[i][1]] != "A" && arr[PositionZombie[i][0] + 1][PositionZombie[i][1]] != "r")
            {
                for (int j = 1; j <= zombies.sizeZombie(); j++)
                {
                    if (arr[PositionZombie[i][0] + 1][PositionZombie[i][1]] == to_string(j))
                    {
                        hitZombie = true;
                    }
                }
                if (hitZombie == false)
                {
                    arr[PositionZombie[i][0]][PositionZombie[i][1]] = " ";
                    PositionZombie[i][0] = PositionZombie[i][0] + 1;
                    arr[PositionZombie[i][0]][PositionZombie[i][1]] = to_string(i + 1);
                }
            }
        }
        else if (move == "left")
        {
            cout << "Zombie " << i + 1 << " moves left." << endl;
            if (PositionZombie[i][1] > 0 && arr[PositionZombie[i][0]][PositionZombie[i][1] - 1] != "A" && arr[PositionZombie[i][0]][PositionZombie[i][1] - 1] != "r")
            {
                for (int j = 1; j <= zombies.sizeZombie(); j++)
                {
                    if (arr[PositionZombie[i][0]][PositionZombie[i][1] - 1] == to_string(j))
                    {
                        hitZombie = true;
                    }
                }
                if (hitZombie == false)
                {
                    arr[PositionZombie[i][0]][PositionZombie[i][1]] = " ";
                    PositionZombie[i][1] = PositionZombie[i][1] - 1;
                    arr[PositionZombie[i][0]][PositionZombie[i][1]] = to_string(i + 1);
                }
            }
        }
        else
        {
            cout << "Zombie " << i + 1 << " moves right." << endl;
            if (PositionZombie[i][1] < column - 1 && arr[PositionZombie[i][0]][PositionZombie[i][1] + 1] != "A" && arr[PositionZombie[i][0]][PositionZombie[i][1] + 1] != "r")
            {
                for (int j = 1; j <= zombies.sizeZombie(); j++)
                {
                    if (arr[PositionZombie[i][0]][PositionZombie[i][1] + 1] == to_string(j))
                    {
                        hitZombie = true;
                    }
                }
                if (hitZombie == false)
                {
                    arr[PositionZombie[i][0]][PositionZombie[i][1]] = " ";
                    PositionZombie[i][1] = PositionZombie[i][1] + 1;
                    arr[PositionZombie[i][0]][PositionZombie[i][1]] = to_string(i + 1);
                }
            }
        }
        cout << endl;
        system("PAUSE");
        system("CLS");
        displayborder(aliens, zombies, arr, row, column, zombie);
        zombieAttack(zombies, aliens, PositionZombie, i, arr, row, column);
        if (aliens.getLife(0) == 0)
        {
            cout << "Alien is defeated." << endl;
            system("PAUSE");
            break;
        }
        cout << endl;
        system("PAUSE");
        system("CLS");
        displayborder(aliens, zombies, arr, row, column, zombie);
    }
}

int main()
{
    system("CLS");      // Clear screen and ready to start the game.
    system("Color E0"); // Change background colour to E = Light Yellow and text colour to 0 = Black.
    int row = 5;
    int column = 9;
    int zombie = 1;
    int rowStart;
    srand(time(NULL));
    Character::Alien aliens;
    Character::Zombie zombies;
    bool arcstar = true;
    bool thermite = false;
    defaultgamesettings(row, column, zombie);
    string **arr = generate2DArr(row, column);
    int **PositionZombie = ZombiePosition(zombie);
    int x = (row - 1) / 2;    // Find the center in the row.
    int y = (column - 1) / 2; // Find the center in the column.
    while (arcstar != false)  // Put the alien into center of the gameboard.
    {
        putRandom(arr, row, column);
        string alien = "A";
        arr[x][y] = alien;
        arcstar = false;
    }
    generateZombie(zombies, zombie, row, column, arr, PositionZombie);
    string command;
    while (thermite != true)
    {
        system("CLS");
        displayborder(aliens, zombies, arr, row, column, zombie);
        typeCommand(command);
        string lastMove;
        string hit;
        if (command == "quit")
        {
            cout << "BYE BYE. Have a nice day. " << endl;
            system("pause");
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            thermite = true;
            break;
        }
        else if (command == "help")
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            help();
            cout << endl;
            system("PAUSE");
        }
        else if (command == "arrow")
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            changeArrow(arr, row, column);
        }
        else if (command == "save")
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Sry system unable to save games." << endl;
            system("PAUSE");
        }
        else if (command == "load")
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Sry system unable to load games." << endl;
            system("PAUSE");
        }
        else if (command == "up" || command == "down" || command == "left" || command == "right")
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            bool alienHitRock = false;
            if (command == "up")
            {
                hit = moveUp(x, y, arr, hit, zombies);
                lastMove = "^";
            }
            else if (command == "down")
            {
                hit = moveDown(x, y, arr, hit, row, zombies);
                lastMove = "v";
            }
            else if (command == "left")
            {
                hit = moveLeft(x, y, arr, hit, zombies);
                lastMove = "<";
            }
            else if (command == "right")
            {
                hit = moveRight(x, y, arr, hit, column, zombies);
                lastMove = ">";
            }
            hitRock(hit, aliens, zombies, lastMove, row, column, arr, x, y, PositionZombie, zombie);
            if (hit == "r")
            {
                alienHitRock = true;
            }
            system("PAUSE");
            while (alienHitRock != true)
            {
                if ((x == 0 && lastMove == "^") || (x == (row - 1) && lastMove == "v") || (y == 0 && lastMove == "<") || (y == (column - 1) && lastMove == ">") || (lastMove <= to_string(zombies.sizeZombie())) || (zombies.accumulateZombieLife() == 0))
                {
                    break;
                }
                else
                {
                    system("CLS");
                    displayborder(aliens, zombies, arr, row, column, zombie);
                    hit = continuousMove(hit, lastMove, x, y, arr, row, column, zombies);
                    hitRock(hit, aliens, zombies, lastMove, row, column, arr, x, y, PositionZombie, zombie);
                    if (hit == "r")
                    {
                        alienHitRock = true;
                    }
                    system("PAUSE");
                }
            }
            system("CLS");
            displayborder(aliens, zombies, arr, row, column, zombie);
            spawnfromtrail(arr, row, column, zombie, rowStart, aliens, zombies);
            system("PAUSE");
            zombieMove(zombies, aliens, row, column, arr, PositionZombie, rowStart, zombie);
            if (zombies.accumulateZombieLife() == 0 || aliens.getLife(0) == 0)
            {
                if (aliens.getLife(0) == 0)
                {
                    cout << "You Lose. Try again next time. " << endl;
                }
                else if (zombies.accumulateZombieLife() == 0)
                {
                    cout << "Alien's won!! Victory!!" << endl;
                }
                while (true)
                {
                    cout << "Do you want to restart the game (y/n)?:";
                    string restart;
                    cin >> restart;
                    cout << endl;
                    if (restart == "n")
                    {
                        thermite = true;
                        break;
                    }
                    else if (restart == "y")
                    {
                        system("CLS");
                        main();
                        thermite = true;
                        break;
                    }
                    else
                    {
                        cout << "Please enter a valid input !" << endl;
                    }
                }
            }
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid command." << endl;
            cout << "You can view the command list by entering command \'help\'." << endl;
            cout << endl;
            system("PAUSE");
        }
    }
}
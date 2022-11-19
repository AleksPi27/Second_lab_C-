#include <iostream>

using namespace std;

void sieveOfEratosthenes(int n, bool isPrime[]) {
    isPrime[0] = isPrime[1] = false;
    for (unsigned int i = 2; i <= n; ++i) {
        isPrime[i] = true;
    }

    for (unsigned int p = 2; p * p <= n; ++p) {
        if (isPrime[p] == true) {
            for (unsigned int j = p * 2; j <= n; j += p) {
                isPrime[j] = false;
            }
        }
    }
}

bool isPrimeNumber(int n) {
    for (unsigned int p = 2; p <= n/2; ++p) {
        if (n % p == 0) {
            return false;
        }
    }
    return n > 1;
}

bool isNumberSuperPrime(int number){
    bool* isPrime= new bool[number + 1];
    sieveOfEratosthenes(number, isPrime);

    int n = 0;
    for (unsigned int p = 2; p <= number; p++) {
        if (isPrime[p]) {
            ++n;
        }
    }
    return isPrimeNumber(n);
}

double biggestAmongThree(double a, double b, double c) {
    if (a >= b && a >= c) {
        return a;
    }
    if (b >= a && b >= c) {
        return b;
    } 
    if (c >= a && c >= b) {
        return c;
    }
}
const unsigned int MAX_COIN = 5000;
int* coinExchange(const unsigned int amount) {
    unsigned int coinSystem[] = {1, 2, 5, 10, 50, 100, 200, 500, 1000, 2000, 5000};
    unsigned int amountCopy = amount;
    int* coinsNumber = new int[MAX_COIN + 1];

    unsigned int iter = 0;
    //cout << "sizeof coinSystem " << sizeof coinSystem << endl;
    //cout << "(sizeof coinSystem[0]) " << (sizeof coinSystem[0]) << endl;
    //cout << "((sizeof coinSystem) / (sizeof coinSystem[0])) - 1 " << ((sizeof coinSystem) / (sizeof coinSystem[0])) - 1 << endl;
    

    for (int iter = ((sizeof coinSystem) / (sizeof coinSystem[0])) - 1; iter >= 0; --iter) {
    //cout << "coinSystem[iter] " << coinSystem[iter] << endl;
        coinsNumber[coinSystem[iter]] = 0;
        if (amountCopy < 0) {
            break;
        }
        if (coinSystem[iter] > amountCopy) {
            continue;
        }
        unsigned int coinNumber = amountCopy / coinSystem[iter];
        coinsNumber[coinSystem[iter]] = coinNumber;
        amountCopy -= coinNumber * coinSystem[iter];
    }
    return coinsNumber;
}

int randomizeCenter() {
    return rand() % 9 - 4;
}

int randomizeHitScore(int center) {
    return rand() % (2 * (center + 3) + 1) - (center+3);
}

int hitScores(int x, int y) {
    int centerX = randomizeCenter();
    int centerY = randomizeCenter();
    cout << "centerX " << centerX << endl;
    cout << "centerY " << centerY << endl;
    int randX = randomizeHitScore(centerX);
    int randY = randomizeHitScore(centerY);
    cout << "randX " << randX << endl;
    cout << "randY " << randY << endl;
    double dist = sqrt(pow(randX -centerX,2) + pow(randY -centerY,2));
    cout << "dist " << dist << endl;
    if (dist <= 1) {
        return 10;
    }
    else if (dist <= 2) {
        return 5;
    }
    else if (dist <= 3) {
        return 1;
    }
    else {
        return 0;
    }
}

int targetShooting() {
    int x, y;
    cout << "Enter x coord of your hit: ";
    cin >> x;
    cout << "Enter y coord of your hit: ";
    cin >> y;
    return hitScores(x, y);
}

string getLevel(int attempts) {
    if (attempts < 5) {
        return "sniper";
    }
    else if (attempts < 10) {
        return "shooter";
    }
    else return "beginner";
}

int main()
    {
    /*int number;
    cout << "Enter the number to be checked: ";
    cin >> number;
    cout << "If is the number super prime? " << boolalpha<<isNumberSuperPrime(number) << endl;*/

    /*double a, b, c;
    cout << "Enter the first number to be compared: ";
    cin >> a;
    cout << "Enter the secondnumber to be compared: ";
    cin >> b;
    cout << "Enter the third number to be compared: ";
    cin >> c;
    cout << "The biggest number among three is " << biggestAmongThree(a, b, c) << endl;*/


    /*unsigned int amount;
    cout << "Enter amount you want to exchange with less russian coins: ";
    cin >> amount; 

    int* resultCoins = coinExchange(amount);

    cout << "We have the following coin exchange for you amount: " << endl;
    for (unsigned int i = 0; i <= MAX_COIN; ++i) {
        if (resultCoins[i] > 0) {
            cout << i << " - " << resultCoins[i] << " coins"<<endl;
        }
    }*/
    srand(time(0));
    int scoresAchieved = 0;
    int attempts = 0;

    while (scoresAchieved < 50 && attempts<20) {
        scoresAchieved += targetShooting();
        cout << "scores achieved " << scoresAchieved << endl;
        attempts++;
    }
    cout << "You gained " << scoresAchieved << " scores" << endl;
    cout << "You are " << getLevel(attempts)<<endl;
}

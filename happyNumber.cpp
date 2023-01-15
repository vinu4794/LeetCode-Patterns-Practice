#include<iostream>
int findSquareSum(int num)
{
    int sum = 0;

    while(num > 0) {
        int digit = num % 10;
        sum += digit*digit;
        num /= 10;
    }

    return sum;
}

bool isHappyNumber(int value)
{
    bool outputBool = false;
    int slow = findSquareSum(value);
    int fast = findSquareSum(findSquareSum(value));

    while(slow != fast) {
        slow = findSquareSum(slow);
        fast = findSquareSum(findSquareSum(fast));
    }

    if (slow == 1) {
        return true;
    } 
    else {
        return false;
    }
}



int main()
{
    bool out = isHappyNumber(12);
    std::cout<<out;

}
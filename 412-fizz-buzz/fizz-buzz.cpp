// Write a program that outputs the string representation of numbers from 1 to n.
//
// But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.
//
// Example:
//
// n = 15,
//
// Return:
// [
//     "1",
//     "2",
//     "Fizz",
//     "4",
//     "Buzz",
//     "Fizz",
//     "7",
//     "8",
//     "Fizz",
//     "Buzz",
//     "11",
//     "Fizz",
//     "13",
//     "14",
//     "FizzBuzz"
// ]
//
//


class Solution {
    private:
    string int2str(int num){
    string str;
    char c;

    while(num){
        c = num % 10 + '0';
        num /= 10;
        str += c;
    }

    string re(str.rbegin(),str.rend());
    return re;
}
public:
    vector<string> fizzBuzz(int n) {
        vector<string> vt;
    string str1 = "Fizz";
    string str2 = "Buzz";
    string str3 = "FizzBuzz";
    for(int i = 1; i <= n ; ++i){
        if(i % 3 == 0 && i % 5 == 0){

            vt.push_back(str3);
        }
        else if(i % 3 == 0 && i % 5 != 0){
            vt.push_back(str1);
        }
        else if(i % 3 != 0 && i % 5 == 0){
            vt.push_back(str2);
        }
        else{
            vt.push_back(int2str(i));
        }

    }
    return vt;
    }
};

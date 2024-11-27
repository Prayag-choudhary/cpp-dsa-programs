#include <iostream>
#include <vector>
using namespace std;

// Arrays to store textual representation
string ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string teens[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
string thousands[] = {"", "thousand", "million", "billion"};

string numberToWords(int num) {
    if (num == 0) return "zero";

    string result = "";

    // Helper function for numbers below 1000
    auto helper = [](int num) -> string {
        string res;
        if (num >= 100) {
            res += ones[num / 100] + " hundred ";
            num %= 100;
        }
        if (num >= 11 && num <= 19) {
            res += teens[num - 10] + " ";
        } else {
            if (num >= 10) {
                res += tens[num / 10] + " ";
                num %= 10;
            }
            if (num > 0) {
                res += ones[num] + " ";
            }
        }
        return res;
    };

    int index = 0;
    while (num > 0) {
        if (num % 1000 != 0) {
            result = helper(num % 1000) + thousands[index] + " " + result;
        }
        num /= 1000;
        index++;
    }

    return result;
}

vector<string> convertVectorToWords(const vector<int>& nums) {
    vector<string> words;
    for (int num : nums) {
        words.push_back(numberToWords(num));
    }
    return words;
}
int numberOfVowels(string text){
    vector<string>vowels={"a","e","i","o","u"};
    int count=0;
    for(int i = 0;i<text.size();i++){
        for(int j = 0;j<vowels.size();j++){
            if(string(1, text[i]) == vowels[j]){
                count++;
                break;
            }
    }
    }
    return count;
}
string totalPairs(int Count,vector<int>arr){
    int totalCount=0;
    for(int i=0;i<arr.size();i++){
        for (int j = 0; j < arr.size(); j++)
        {
            
            if(arr[i]+arr[j] == Count ){

                totalCount++;
            }
        }
    }
    string s=numberToWords(totalCount);
    return s;
}
int main() {
    int number;
    
    
    cout << "Enter a number: ";
    cin >> number;
    cout << "Enter a array: ";
    vector<int>arr;
    int i,t,value,total_count_vowels=0;
    for(int i=0;i<number;++i){
        cin >> value;
        arr.push_back(value);
    }
    vector<string>arr_text=convertVectorToWords(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr_text[i]<<endl;
    }
    for(int i=0;i<arr.size();i++){
        value=numberOfVowels(arr_text[i]);
        total_count_vowels=total_count_vowels+value;
    }
    
    string result = totalPairs(total_count_vowels,arr);
    cout<<"total numbers of pairs are :"<<result;

}

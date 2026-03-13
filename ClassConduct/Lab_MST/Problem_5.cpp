/*
You start with an initial power of power, an initial score of  0, and a bag of tokens given
as an integer array token, where each token[i] denotes the value of token.

You goal is to maximize the total score by strategically playing these tokens. 
In one move, you can play an unplayed token in one of the two ways:

-   Face_up: If current power is at least tokens[i], you may play token, losing tokens[i] power 
    and gaining 1 score.

-   Face_down: If current score is at least 1, you may play token, gaing tokens[i] power and 
    losing 1 score.

Return the maximum possible score you can achieve after playing any number of tokens.
*/

#include <bits/stdc++.h>

using namespace std;

int Score(vector<int>& tokens, int power) {
    sort(tokens.begin(), tokens.end());
    int score = 0;
    int temp_score = 0;
    int left = 0, right = tokens.size() - 1;

    while (left <= right) {
        if (power >= tokens[left]) {
            power -= tokens[left];
            temp_score++;
            left++;
            score = max(score, temp_score);
        } else if (score > 0) {
            power += tokens[right];
            temp_score--;
            right--;
            score = max(score, temp_score);
        } else {
            break;
        }
    }

    return score;
}

int main() {
    vector<int> tokens = {50};
    int power = 100;
    cout << Score(tokens, power) << endl; // Output: 1

    tokens = {100, 200};
    power = 150;
    cout << Score(tokens, power) << endl; // Output: 1
    return 0;
}
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b = 0;
        int a = 0;
        int l = 0;
        int o = 0;
        int n = 0;
        for(char ch : text){
            if(ch == 'b'){
                b++;
            }
            else if(ch == 'a'){
                a++;
            }
            else if(ch == 'l'){
                l++;
            }
            else if(ch == 'o'){
                o++;
            }
            else if(ch == 'n'){
                n++;
            }
            
        }
        return min({b,a,( l /2), (o/2), n});
    }

};
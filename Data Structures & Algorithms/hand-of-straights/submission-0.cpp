class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
       if((n%groupSize)!=0)
       return false;
       sort(hand.begin(),hand.end());
       map<int,int>mp;
       for(int i=0;i<n;i++){
        mp[hand[i]]++;
       }
       while(!mp.empty()){
         int start=mp.begin()->first;
         for(int i=0;i<groupSize;i++){
              int x=start+i;
              if(mp.find(x)==mp.end())
              return false;
              mp[x]--;
              if(mp[x]==0)
              mp.erase(x);
         }
       }
       return true;

    }
};
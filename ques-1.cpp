#include<bits/stdc++.h>
using namespace std;

string dayofweek(int d, int m, int y)  
{  
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };  
    y -= m < 3;  
    int x= ( y + y / 4 - y / 100 +   y / 400 + t[m - 1] + d) % 7; 

    string day[] = {"Sunday","Monday","Tuesday","Wednesday", "Thursday", "Friday", "Saturday"};
     return day[x]; 
 
} 

int year,month,date;
void extractfromstring(string s){
  int yr=stoi(s.substr(0,4));
  int pos=s.find('-');
  int x=pos+3;
  string temp;
  for (int i=pos+1;i<x;i++){
    temp+=s[i];
  }
  int mon=stoi(temp);
  temp.clear();
  int n=s.size();
  x=n-3;
  for (int i=n-1;i>x;i--){
    temp+=s[i];
  }
  reverse(temp.begin(), temp.end());
  int dte=stoi(temp);

  
year=yr;
date=dte;
month=mon;
}

int main(){

  map<string,int>mp={{"2020-01-01",4},{"2020-01-02",4},{"2020-01-03",6,},{"2020-01-04",8},{"2020-01-05",2},{"2020-01-06",-6},{"2020-01-07",2},{"2020-01-08",-2}};
 
  map<string,int>ans;
  for (auto x:mp){
    string a=x.first;
    extractfromstring(a);
    int d=date;
    int m=month;
    int y=year;
    int b=x.second;
    string day=dayofweek(d,m,y); 
    ans[day]+=b;
  }

  for (auto x:ans){
    cout<<x.first<<" "<<x.second<<endl;
  }
 
  
     

}

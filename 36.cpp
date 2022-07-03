class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans=true;
         vector<int> temp={},temp1={},temp2={},temp3={},temp4={};
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                
                 if(board[j][i]!='.'){
                     temp4.push_back(board[j][i]);    //column gulor jonno
                 }
                
               if(board[i][j]!='.'){
                   temp.push_back(board[i][j]);  //row gulor jpnno
                   
                   
                   if(j<=2){
                      temp1.push_back(board[i][j]);   //first 3*3 ta 
                   }
                   else if(j<=5){
                       temp2.push_back(board[i][j]); //second 3*3 ta
                   }
                   
                   else if(j<=8){
                       temp3.push_back(board[i][j]);  //third 3*3 ta 
                   }
                   
                   
               }
               
            }
            //ebar same kina dekhchi sort kore
            if(i==2 || i==5 || i==8){
                
                       sort(temp1.begin(),temp1.end());
                       sort(temp2.begin(),temp2.end());
                       sort(temp3.begin(),temp3.end());
                
                        
                       for(int i=0;i<=8;i++){
                           
                           if((i+1)<temp1.size()){
                               if(temp1[i]==temp1[i+1]){
                                   ans=false;
                                   break;
                               }
                           }
                           
                          if((i+1)<temp2.size()){
                               if(temp2[i]==temp2[i+1]){
                                   ans=false;
                                   break;
                               }
                           }
                           
                           if((i+1)<temp3.size()){
                               if(temp3[i]==temp3[i+1]){
                                   ans=false;
                                   break;
                               }
                           }
                           
                       }
                       
                       temp1.clear();
                       temp2.clear();
                       temp3.clear();
                   }
            
            sort(temp.begin(),temp.end());
            sort(temp4.begin(),temp4.end());
            
            
            int tempsize = temp.size()-1;
            int temp4size = temp4.size()-1;
            
            for(int p=0;p<tempsize;p++){
                if(temp[p]==temp[p+1]){
                    ans=false;
                    break;
                }
            }
            
            for(int p=0;p<temp4size;p++){
                if(temp4[p]==temp4[p+1]){
                    ans=false;
                    break;
                }
            }
            
            
            temp.clear();
            temp4.clear();
            
            
            if(ans==false){
                break;
            }
        }
        
        return ans;
    }
};

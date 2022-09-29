const int max_size=26;
class Solution {
public:
    
    struct TrieNode{
        TrieNode* children[max_size];
        bool isend;
    };
    TrieNode* getNode(){
        TrieNode* root=new TrieNode();
        root->isend=false;
        for(int i=0;i<26;i++)root->children[i]=NULL;
        return root;
    }
    void insert(TrieNode* root,string &s){
        TrieNode* temp=root;
        for(int i=0;i<s.size();i++){
            if(temp->children[s[i]-'a']==NULL){
                TrieNode* newNode=getNode();
                temp->children[s[i]-'a']=newNode;
            }
            temp=temp->children[s[i]-'a'];
        }
        temp->isend=true;
    }
    string replaceWords(vector<string>& dictionary, string sen) {
        TrieNode* root=getNode();
        for(int i=0;i<dictionary.size();i++){
            insert(root,dictionary[i]);
        }
        string res="";
        for(int i=0;i<sen.size();i++){
            string word="";
            while(sen[i]!=' ' && i<sen.size()){word.push_back(sen[i]);i++;}
            TrieNode* temp=root;
            for(int j=0;j<word.size();j++){
                //if(temp==NULL){
                //    cout<<word[j]<<endl;
                //}
                if(temp)if(temp->isend==true)break;
                res.push_back(word[j]);
                if(temp)temp=temp->children[word[j]-'a'];
            }
            if(i<sen.size())res.push_back(' ');
        }
        return res;
    }
};
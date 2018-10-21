#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct dictTree{
    char word[11],c;
    struct dictTree *children;
}dictTree;
int main(){
    int i,j,flag;
    char tmp[30],a[11],b[11];
    dictTree tree[26],*node;
    while(gets(tmp)&&tmp[0]!='\0'){
        sscanf(tmp,"%s%s",b,a);
        node = &tree[a[0]-'a'];
        if(node->c!=a[0]){
            node->c=a[0];
            node->children=(dictTree *)malloc(sizeof(dictTree)*26);
        }
            
        for(i=1;i<strlen(a);i++){
            node = &node->children[a[i]-'a'];
            if(node->c!=a[i]){
                node->children=(dictTree *)malloc(sizeof(dictTree)*26);
                node->c=a[i];
            }
        }
        strcpy(node->word,b);
    }
    while(gets(tmp)&&tmp[0]!='\0'){
        sscanf(tmp,"%s",a);
        flag=0;
        node = &tree[a[0]-'a'];
        for(i=0;i<strlen(a);i++){
            
            if(node->c!=a[i]){
                flag=1;
                break;
            }
            else if(i==strlen(a)-1){
                break;
            }
            node = &node->children[a[i+1]-'a'];
        }
        if(flag==1)
            printf("eh\n");
        else{
            printf("%s\n",node->word);
        }
    }
    return 0;
}
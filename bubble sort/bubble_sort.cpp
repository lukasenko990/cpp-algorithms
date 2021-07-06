#include <iostream>
//Bubble sort
void bubble_sort (std::string words [] ,int numbers [], int size ){
for(int i=size-1;i>0;i--)
{
    //tmp variables are responsible for saving string and int for swapping its places in tab
    std::string word_tmp;
    int number_tmp;
    int max=0;
    for(int j=1;j<=i;j++)
    {
        if(numbers[max]<numbers[j]) max=j;
        //if numbers are equal the order is determined by strings
        if(numbers[max]==numbers[j]) if(words[max]<words[j]) max=j;
    }
    number_tmp=numbers[max];
    numbers[max]=numbers[i];
    numbers[i]=number_tmp;
    word_tmp=words[max];
    words[max]=words[i];
    words[i]=word_tmp;
}
}
int main()
{
    int size;
    std::cin>>size;
    std::string words[size];
    int numbers[size];
    for(int j=0;j<size;j++)
    {
        std::cin>>words[j]>>numbers[j];
    }
    bubble_sort(words,numbers,size);
    for(int j=0;j<size;j++)
    {
        std::cout<<words[j]<<" "<<numbers[j]<<std::endl;
    }
    return 0;
}

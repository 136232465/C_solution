class Solution{  
public:  
    int rand7(){  
        int ran;  
        while((ran = rand5()*5+rand5())>=21);//如果产生的数大于20那么就重复再取数  
        return ran/3;//比如0,1,2除以3则对应数字0，因此直接将结果除以3  
    }  
private:  
    int rand5(){  
        return rand()%5;//产生[0,4]范围的随机整数  
    }  
};  
int dividir(int a, int b, int *res){

    if(b==0){
        return 0; 
    }else{
        *res=a/b;
        return 1; 
    }

}   
main(a,i){
    scanf("%d",&a);

    for(i=32;i-->0;){
        // if(a&(1<<i))printf("1");
        // else printf("0");
        a&(1<<i)?printf("1"):printf("0");
    }
}
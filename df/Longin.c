int Longin()
{//登录功能
    //extern void load();
    char *admin;//默认用户名
    admin = read_file("user.txt",1);
    char *passwd = read_file("passwd.txt",2);//默认密码
    char admin_user[30];
    char passwd_user[30];//用户输入密码·
    printf("请输入用户名\n");
    gets(admin_user);
    printf("请输入密码\n");
    gets(passwd_user);
    
    if (strcmp(admin,admin_user)==0&&strcmp(passwd,passwd_user)==0)
    {
        printf("登录成功\n");
        return 1;

        /* code */
    }
    else
    {
        printf("登录失败,请检查用户名或密码\n");
        puts(admin);
        return 0;

    }
    
    
    
}
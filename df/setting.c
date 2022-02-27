//设置
void Setting()
{
    
    printf("\t\t##########################\n");
    printf("\t\t# 1.修改用名             #\n");
    printf("\t\t# 2.修改密码             #\n");
    printf("\t\t# 0.退出                 #\n");
    printf("\t\t##########################\n");
    printf("请输入功能\n");
    int sel;
    char user_name[20];
    int num;
    scanf("%d",&sel);
    switch (sel)
    {
    case 0:
        break;
    case  1:
        /* code */
        printf("请输入要修改的用户名\n");
        scanf("%s",user_name);
        num = witre_file("user.txt",1,user_name);
        if (num == 0)
        {
            printf("修改成功请重启\n");
            exit(0);
        }
        else
        {
            printf("修改失败请重新修改\n");
            break;
            /* code */
        }
        break;
    case 2:
        printf("请输入要修改的密码\n");
        scanf("%s",user_name);

        num = witre_file("passwd.txt",2,user_name);
        if (num == 1)
        {
            printf("修改成功请重启\n");
            exit(0);
        }
        else
        {
            printf("修改失败请重新修改\n");
            break;
            /* code */
        }
        break;

    
    default:
        break;
    }

}

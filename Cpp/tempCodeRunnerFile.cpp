    CStudent s;
    ofstream OutFile("E:\\VS-Code\\VS-Code-C\\student.dat",ios::out|ios::binary);
    while(cin>>s.szName>>s.nScore)
    {
        if(stricmp(s.szName,"exit")==0)    //如果输入为exit 则break
        {
            break;
        }
        OutFile.write((char*)&s,sizeof(s));
    }
    OutFile.close();
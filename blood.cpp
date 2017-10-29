#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define endl '\n'
using namespace std;

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

void split(const std::string &s, std::vector<std::string> &elems,char delim) {
    split(s, delim, std::back_inserter(elems));
}
void readfile(string,string,string);
void readfile(string,string,int);
void readfile(string);
//********************************CLASS DONOR_DETAILS**********************
class Donor_details
{
  string name,gender,city,blood;// add ailments later
  ll phone,age;
  friend class Admin;
  friend class Staff;
public:
  void getdata();
  friend void putdata1(Donor_details &d);
};
void putdata1(Donor_details &d)
{
  cout<<"\n Enter your details";
  cout<<"\n Full name: ";
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  getline(cin,d.name);
  cout<<"\n Gender: ";
  getline(cin,d.gender);
  cout<<"\n City/Town: ";
  getline(cin,d.city);
  cout<<"\n Blood group: ";
  getline(cin,d.blood);
  cout<<"\n Age: ";
  cin>>d.age;
  while (cin.fail())
  {
      cin.clear(); // clear input buffer to restore cin to a usable state
      cin.ignore(INT_MAX, '\n'); // ignore last input
      cout<<"\n Invalid age.";
      cout<<"\n age: ";
      cin>>d.age;
  }
  Z:cout<<"\n Phone Number: +91";
  cin>>d.phone;
  while (cin.fail())
  {
      cin.clear(); // clear input buffer to restore cin to a usable state
      cin.ignore(INT_MAX, '\n'); // ignore last input
      cout<<"\n Invalid phone number. \n Please provide a valid phone number";
      goto Z;
  }
  if(!(d.phone > 999999999 && d.phone < 10000000000))
  {
    cout<<"\n Invalid phone number Entered. \n Please provide a valid phone number";
    goto Z;
  }
  ofstream x("citizen.csv",ios::app|ios::ate);
  x<<d.name<<','<<d.gender<<','<<d.city<<','<<d.blood<<','<<d.age<<','<<d.phone<<endl;
}

void Donor_details::getdata() {
  string city1,bg1;
  cout<<"\n Search on the Basis of: ";
  cout<<"\n 1. City";
  cout<<"\n 2. Blood Group";
  cout<<"\n 3. Both City and Blood Group";
  cout<<"\n Enter your choice: ";
  int i;
  cin>>i;
  switch(i)
  {
  case 1: cout<<"\n Enter name of the city: ";
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          getline(cin,city1);
          readfile("citizen",city1,2);
          break;
  case 2: cout<<"\n Enter blood group: ";
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          getline(cin,bg1);
          readfile("citizen",bg1,3);
          break;
  case 3: cout<<"\n Enter name of city: ";
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          getline(cin,city1);
          cout<<"\n Enter blood group: ";
          getline(cin,bg1);
          readfile("citizen",bg1,city1);
          break;
  default : cout<<"\n Invalid input";
  }
  }

  //***********************************Class User*******************************
  class user
  {
    char status; /*status in the system if Admin= admin
                                           Staff= staff
                                           Normal user= citizen */
  public:
    virtual void getdata()=0;
    virtual void putdata(){}
    virtual void deletedata(){}
    virtual int check_passwd(string login1){}
    virtual int check_login(string stat){}

  };

//*******************************Class Admin**************************************
class Admin : public user
{
  string login,passwd;
public:
  void getdata();
  void putdata();
  //void edit_acc();
  void deletedata();
  int check_passwd(string);
  int check_login(string stat);
};

/*void edit_acc()
{

}*/



int Admin::check_passwd(string login)
{
  ifstream x("admin.csv");
  string s;
  while (std::getline(x, s))
   {
     std::vector<string> v;
     split(s,v,',');
     for(int i=0;i<v.size();i++)
     {
       if(v[6]==login)
       {
         cout<<"\n LoginID already exists";
         return 1;
       }
    }
  }
  return 2;
}

void Admin::deletedata()
{
string login1,login,name,gender,city,blood,passwd,age,phone;
int ctr;
  cout<<"\n Delete From:";
  cout<<"\n 1. Admin";
  cout<<"\n 2. Staff";
  cout<<"\n 3. Donor";
  int i;
  cout<<"\n Enter your choice: ";
  cin>>i;
  switch(i)
  {
    case 1: {getchar();
              cout<<"\n Enter ID of the person whose account needs to be deleted: ";
              getline(cin,login1);
              ctr=0;
              ifstream x("admin.csv");

              string s;
              ofstream y("adminnew.csv");
              while (std::getline(x, s)) {
              std::vector<string> v;
              split(s,v,',');
              for(int i=0;i<v.size();i++)
                {
                  name=v[0];
                  gender=v[1];
                  city=v[2];
                  blood=v[3];
                  age=v[4];
                  phone=v[5];
                  login=v[6];
                  passwd=v[7];
                  if(v[6]==login1)
                {
                  ctr++;
                  break;
                }
                else
                {
                  y<<name<<','<<gender<<','<<city<<','<<blood<<','<<age<<','<<phone<<','<<login<<','<<passwd<<endl;
                  break;
                }
              }
          }
          if(ctr==0)
          cout<<"\n No such admin found.";
          else
          cout<<"\n Successfully deleted admin with ID "<<login1<<".";
          remove("admin.csv");
          rename("adminnew.csv", "admin.csv");

            }break;

    case 2: {getchar();
              cout<<"\n Enter ID of the person whose account needs to be deleted: ";
              getline(cin,login1);
              ctr=0;
              ifstream x("staff.csv");

              string s;
              ofstream y("staffnew.csv");
              while (std::getline(x, s)) {
              std::vector<string> v;
              split(s,v,',');
              for(int i=0;i<v.size();i++)
                {
                  name=v[0];
                  gender=v[1];
                  city=v[2];
                  blood=v[3];
                  age=v[4];
                  phone=v[5];
                  login=v[6];
                  passwd=v[7];
                  if(v[6]==login1)
                {
                  ctr++;
                  break;
                }
                else
                {
                  y<<name<<','<<gender<<','<<city<<','<<blood<<','<<age<<','<<phone<<','<<login<<','<<passwd<<endl;
                  break;
                }
              }
          }
          if(ctr==0)
          cout<<"\n No such staff found.";
          else
          cout<<"\n Successfully deleted staff with ID "<<login1<<".";
          remove("staff.csv");
          rename("staffnew.csv", "staff.csv");

            }break;
    case 3: {getchar();
              cout<<"\n Enter name of the person whose account needs to be deleted: ";
              getline(cin,login1);
              ctr=0;
              ifstream x("citizen.csv");

              string s;
              ofstream y("citizennew.csv");
              while (std::getline(x, s)) {
              std::vector<string> v;
              split(s,v,',');
              for(int i=0;i<v.size();i++)
                {
                  name=v[0];
                  gender=v[1];
                  city=v[2];
                  blood=v[3];
                  age=v[4];
                  phone=v[5];
                  if(v[0]==login1)
                {
                  ctr++;
                  break;
                }
                else
                {
                  y<<name<<','<<gender<<','<<city<<','<<blood<<','<<age<<','<<phone<<endl;
                  break;
                }
              }
          }
          if(ctr==0)
          cout<<"\n No such donor found.";
          else
          cout<<"\n Successfully deleted donor with name "<<login1<<".";
          remove("citizen.csv");
          rename("citizennew.csv", "citizen.csv");

            }break;
    default: cout<<"\n Invalid Choice";
  }
}


void Admin::getdata() // Retrive data from Database
{ string name1,city1,bg1;
  cout<<"\n 1. Search";
  cout<<"\n 2. View the list";
  cout<<"\n Enter your choice: ";
  int i,k;
  cin>>k;
  if(k==1)
  {
    cout<<"\n Whom do you want to Search?";
    cout<<"\n 1. Donor";
    cout<<"\n 2. Staff";
    cout<<"\n 3. Admin";
    cout<<"\n Enter your choice: ";
    cin>>i;
    switch(i)
    {
      case 1: {
                Donor_details d;//Retrive data about the DONOR
                d.getdata();
              }
              break;
      case 2: {
              cout<<"Search all the Staffs";
              cout<<"\n Search on the Basis of:-";
              cout<<"\n 1. Name";
              cout<<"\n 2. City";
              cout<<"\n 3. Blood Group";
              cout<<"\n 4. Both City and Blood Group";
              cout<<"\n Enter your choice: ";
              int j;
              cin>>j;
              switch (j) {
                case 1: cout<<"\n Enter name of the staff: ";
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        getline(cin,name1);
                        readfile("staff",name1,1);
                        break;
                case 2: cout<<"\n Enter name of city: ";
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        getline(cin,city1);
                        readfile("staff",city1,2);
                        break;
                case 3: cout<<"\n Enter blood group: ";
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        getline(cin,bg1);
                        readfile("staff",bg1,3);
                        break;
                case 4: cout<<"\n Enter name of city: ";
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        getline(cin,city1);
                        cout<<"\n Enter blood group: ";
                        getline(cin,bg1);
                        readfile("staff",bg1,city1);
                        break;
                }
              }
                break;
      case 3: {
              cout<<"Search all the Admins";
              cout<<"On the basis of";
              cout<<"\n Search on the Basis of:-";
              cout<<"\n 1. Name";
              cout<<"\n 2. City";
              cout<<"\n 3. Blood Group";
              cout<<"\n 4. Both City and Blood Group";
              cout<<"\n Enter your choice: ";
              int j;
              cin>>j;
              switch (j) {
                        case 1: cout<<"\n Enter name of the admin: ";
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                getline(cin,name1);
                                readfile("admin",name1,1);
                                break;
                        case 2: cout<<"\n Enter name of city: ";
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                getline(cin,city1);
                                readfile("admin",city1,2);
                                break;
                        case 3: cout<<"\n Enter blood group: ";
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                getline(cin,bg1);
                                readfile("admin",bg1,3);
                                break;
                        case 4: cout<<"\n Enter name of city: ";
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                getline(cin,city1);
                                cout<<"\n Enter blood group: ";
                                getline(cin,bg1);
                                readfile("admin",bg1,city1);
                                break;

                                }}
                        break;
          default:cout<<"\n Invalid input";
    }
  }
  else if(k==2)
  {
    cout<<"\n VIEW THE ENTIRE LIST ";
    cout<<"\n 1. Administrators";
    cout<<"\n 2. Staff members";
    cout<<"\n 3. Donors";
    cout<<"\n Enter your choice: ";
    int j;
    cin>>j;
    switch (j) {
      case 1: {readfile("admin");}
              break;
      case 2: {readfile("staff");}
              break;
      case 3: {readfile("citizen");}break;
    }
  }
}

void Admin::putdata()
{
  Donor_details d;
  cout<<"\n Add new:";
  cout<<"\n 1. Admin";
  cout<<"\n 2. Staff";
  cout<<"\n 3. Donor";
  int i;
  cout<<"\n Enter your choice: ";
  cin>>i;
  switch(i)
  {
    case 1: {
            cout<<"\n Enter your details";
            cout<<"\n Full name: ";
            cin.clear();
	          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin,d.name);
            cout<<"\n Gender: ";
            getline(cin,d.gender);
            cout<<"\n City/Town: ";
            getline(cin,d.city);
            cout<<"\n Blood Group: ";
            getline(cin,d.blood);
            cout<<"\n age: ";
            cin>>d.age;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n'); // ignore last input
                cout<<"\n Invalid age.";
                cout<<"\n age: ";
                cin>>d.age;
            }
            A:cout<<"\n Phone Number: +91";
            cin>>d.phone;
            while (cin.fail())
            {
                cin.clear(); // clear input buffer to restore cin to a usable state
                cin.ignore(INT_MAX, '\n'); // ignore last input
                cout<<"\n Invalid phone number. \n Please provide a valid phone number";
                goto A;
            }
            if(!(d.phone > 999999999 && d.phone < 10000000000))
            {
              cout<<"\n Invalid phone number. \n Please provide a valid phone number";
              goto A;
            }
            getchar();

        do{
          cout<<"\n Enter your LoginID: ";
          getline(cin,login);
        }while(check_passwd(login)==1);

        cout<<"\n Enter your Password: ";
        getline(cin,passwd);

        ofstream x("admin.csv",ios::app|ios::ate);
        x<<d.name<<','<<d.gender<<','<<d.city<<','<<d.blood<<','<<d.age<<','<<d.phone<<','<<login<<','<<passwd<<endl;

        }
            break;
    case 2: {
            cout<<"\n Enter your details";
            cout<<"\n Full name: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin,d.name);
            cout<<"\n Gender: ";
            getline(cin,d.gender);
            cout<<"\n City/town: ";
            getline(cin,d.city);
            cout<<"\n Blood Group: ";
            getline(cin,d.blood);
            cout<<"\n Age: ";
            cin>>d.age;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n'); // ignore last input
                cout<<"\n Invalid age.";
                cout<<"\n age: ";
                cin>>d.age;
            }
            C:cout<<"\n Phone Number: +91";
            cin>>d.phone;
            while (cin.fail())
            {
                cin.clear(); // clear input buffer to restore cin to a usable state
                cin.ignore(INT_MAX, '\n'); // ignore last input
                cout<<"\n Invalid phone number. \n Please provide a valid phone number";
                goto A;
            }
            if(!(d.phone > 999999999 && d.phone < 10000000000))
            {
              cout<<"\n Invalid phone number. \n Please provide a valid phone number";
              goto C;
            }
              getchar();
            do{
              cout<<"\n Enter your LoginID: ";
              getline(cin,login);
            }while(check_passwd(login)==1);

            cout<<"\n Enter your Password: ";
            getline(cin,passwd);

            ofstream x("staff.csv",ios::app|ios::ate);
            x<<d.name<<','<<d.gender<<','<<d.city<<','<<d.blood<<','<<d.age<<','<<d.phone<<','<<login<<','<<passwd<<endl;

          }
            break;
    case 3: putdata1(d);
            break;
    default: cout<<"\n Invalid choice";
  }
}

int Admin::check_login(string stat)
{
  string login1,passwd1;
  cout<<" \n Username: ";
  getline(cin,login1);
  cout<<"\n Password: ";
  getline(cin,passwd1);

  if(stat=="admin")
  {
    ifstream x("admin.csv");
    string s;


while (std::getline(x, s)) {
    // output the line
    std::vector<string> v;
    split(s,v,',');
    for(int i=0;i<v.size();i++)
      {
        if(v[6]==login1 && v[7]==passwd1)
      {
        cout<<"\n Login successful";
        return 1;
      }
    }


}
cout<<"\n Login Failed!!!";
return 2;


  }
}

//********************************Class Staff**************************************

class Staff: public user
{
  string login,passwd;
public:
  void getdata();
  void putdata();
  int check_passwd(string,string);
  int check_login(string stat);;
};

void Staff::putdata()
{
  Donor_details d;
  putdata1(d);
}

int Staff::check_passwd(string login1,string passwd1)
{
  string s;
  ifstream x("staff.csv");
  while (std::getline(x, s))
  {
    std::vector<string> v;
    split(s,v,',');
    for(int i=0;i<v.size();i++)
    {
      if(v[6]==login1)
      {
        cout<<"\n LoginID already exists";
        return 1;
      }
    }
  }
  return 2;
}

  void Staff::getdata()
  {
    string name1,city1,bg1;
      cout<<"\n 1. Search";
      cout<<"\n 2. View the list";
      cout<<"\n Enter your choice: ";
      int i,k;
      cin>>k;
      if(k==1)
      {
        cout<<"\n Whom do you want to Search?";
        cout<<"\n 1. Donor";
        cout<<"\n 2. Staff";

        cout<<"\n Enter your choice: ";
        cin>>i;
        switch(i)
        {
          case 1: {
                    Donor_details d;//Retrive data about the DONOR
                    d.getdata();
                  }
                  break;
          case 2: {
                  cout<<"Search all the Staffs";
                  cout<<"\n Search on the Basis of:-";
                  cout<<"\n 1. Name";
                  cout<<"\n 2. City";
                  cout<<"\n 3. Blood Group";
                  cout<<"\n 4. Both City and Blood Group";
                  cout<<"\n Enter your choice: ";
                  int j;
                  cin>>j;
                  switch (j) {
                    case 1: cout<<"\n Enter name of the staff: ";
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            getline(cin,name1);
                            readfile("staff",name1,1);
                            break;
                    case 2: cout<<"\n Enter name of city: ";
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            getline(cin,city1);
                            readfile("staff",city1,2);
                            break;
                    case 3: cout<<"\n Enter blood group: ";
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            getline(cin,bg1);
                            readfile("staff",bg1,3);
                            break;
                    case 4: cout<<"\n Enter name of city: ";
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            getline(cin,city1);
                            cout<<"\n Enter blood group: ";
                            getline(cin,bg1);
                            readfile("staff",bg1,city1);}
                            break;
                    }
                    break;
              default:cout<<"\n Invalid input";
        }
      }
      else if(k==2)
      {
        cout<<"\n VIEW THE ENTIRE LIST ";

        cout<<"\n 1. Staff members";
        cout<<"\n 2. Donors";
        cout<<"\n Enter your choice: ";
        int j;
        cin>>j;
        switch (j) {
          case 1: {readfile("staff");}
                  break;
          case 2: {readfile("citizen");}break;
        }
      }
  }

  int Staff::check_login(string stat)
  {
    string login1,passwd1;
    cout<<" \n Username: ";
    getline(cin,login1);
    cout<<"\n Password: ";
    getline(cin,passwd1);

    if(stat=="staff")
    {
      ifstream x("staff.csv");
      string s;
      while (std::getline(x, s)) {
      // output the line
      std::vector<string> v;
      split(s,v,',');
      for(int i=0;i<v.size();i++)
        {
          if(v[6]==login1 && v[7]==passwd1)
        {
          cout<<"\n Login successful";
          return 1;
        }
      }


  }
  cout<<"\n Login Failed!!";
  return 2;


    }
  }

//*******************************Class Normal user*******************************
class citizen : public user
{
public:
  void getdata()
  {
    Donor_details d;
    d.getdata();
  }
};

//******************************Reading the file*******************************

void readfile(string stat)
{
  string s;
  string login,passwd,name,gender,city,blood;
  string phone,age;
  if(stat=="admin")
  {
    ifstream x("admin.csv");

    while (std::getline(x, s)) {

        std::vector<string> v;
        split(s,v,',');

        name=v[0];

        gender=v[1];

        city=v[2];

        blood=v[3];

        age=v[4];

        phone=v[5];

        login=v[6];


      cout<<"\n Full name: "<<name<<"\n Gender: "<<gender<<"\n City/Town: "<<city<<"\n Blood Group: "<<blood<<"\n Age: "<<age<<"Phone Number: "<<phone<<"\n Username "<<login<<"\n Password: "<<"********"<<endl;
          }
  }

  if(stat=="staff")
  {
    ifstream x("staff.csv");

    while (std::getline(x, s)) {

        std::vector<string> v;
        split(s,v,',');

        name=v[0];

        gender=v[1];

        city=v[2];

        blood=v[3];

        age=v[4];

        phone=v[5];

        login=v[6];


        cout<<"\n Full name: "<<name<<"\n Gender: "<<gender<<"\n City/Town: "<<city<<"\n Blood Group: "<<blood<<"\n Age: "<<age<<"Phone Number: "<<phone<<"\n Username "<<login<<"\n Password: "<<"********"<<endl;
          }
  }

  if(stat=="citizen")
  {
    ifstream x("citizen.csv");

    while (std::getline(x, s)) {

        std::vector<string> v;
        split(s,v,',');

        name=v[0];

        gender=v[1];

        city=v[2];

        blood=v[3];

        age=v[4];

        phone=v[5];



        cout<<"\n Full name: "<<name<<"\n Gender: "<<gender<<"\n City/Town: "<<city<<"\n Blood Group: "<<blood<<"\n Age: "<<age<<"\n Phone Number: "<<phone<<endl;
          }
  }


}

void readfile(string ch, string ch1, int j)//ch= status, ch1= variable & this func is used to search on the basis of blood group or name or city
{
  int ctr;
  if(ch=="admin")
  {
    if(j==1)
    {
      ctr=0;
      ifstream x("admin.csv");
      string s;
      while (std::getline(x, s)) {
          std::vector<string> v;
          split(s,v,',');
          for(int i=0;i<v.size();i++)
            {
              if(v[0]==ch1)
            {
              cout<<"\n+++++++++++++++++++++++++++++++++++++++++++ \n";
              cout<<"Name: "<<v[0]<<endl;
              cout<<"Gender: "<<v[1]<<endl;
              cout<<"City/town: "<<v[2]<<endl;
              cout<<"Blood Group: "<<v[3]<<endl;
              cout<<"Age: "<<v[4]<<endl;
              cout<<"Phone number: "<<v[5]<<endl;
              cout<<"LoginID: "<<v[6]<<endl;
              ctr++;
              break;
            }
          }
      }
      if(ctr==0)
      cout<<"\nAdmin with no such name exists!";
      else
      cout<<"\nSuccessfully displayed "<<ctr<<" admins.";

    }

    if(j==2)
    {
      ctr=0;
      ifstream x("admin.csv");
      string s;
      while (std::getline(x, s)) {
          std::vector<string> v;
          split(s,v,',');
          for(int i=0;i<v.size();i++)
            {
              if(v[2]==ch1)
            {
              cout<<"\n+++++++++++++++++++++++++++++++++++++++++++ \n";
              cout<<"Name: "<<v[0]<<endl;
              cout<<"Gender: "<<v[1]<<endl;
              cout<<"City/town: "<<v[2]<<endl;
              cout<<"Blood Group: "<<v[3]<<endl;
              cout<<"Age: "<<v[4]<<endl;
              cout<<"Phone number: "<<v[5]<<endl;
              cout<<"LoginID: "<<v[6]<<endl;
              ctr++;
              break;
            }
          }
      }
      if(ctr==0)
      cout<<"\nNo admin in such city found.";
      else
      cout<<"\nSuccessfully displayed "<<ctr<<" admins.";
    }

    if(j==3)
    {
      ctr=0;
      ifstream x("admin.csv");
      string s;
      while (std::getline(x, s)) {
          std::vector<string> v;
          split(s,v,',');
          for(int i=0;i<v.size();i++)
            {
              if(v[3]==ch1)
            {
              cout<<"\n+++++++++++++++++++++++++++++++++++++++++++ \n";
              cout<<"Name: "<<v[0]<<endl;
              cout<<"Gender: "<<v[1]<<endl;
              cout<<"City/town: "<<v[2]<<endl;
              cout<<"Blood Group: "<<v[3]<<endl;
              cout<<"Age: "<<v[4]<<endl;
              cout<<"Phone number: "<<v[5]<<endl;
              cout<<"LoginID: "<<v[6]<<endl;
              ctr++;
              break;
            }
          }
      }
      if(ctr==0)
      cout<<"\nNo admin with such blood group found.";
      else
      cout<<"\nSuccessfully displayed "<<ctr<<" admins.";
    }

  }

  if(ch=="staff")
  {

      if(j==1)
      {
        ctr=0;
        ifstream x("staff.csv");
        string s;
        while (std::getline(x, s)) {
            std::vector<string> v;
            split(s,v,',');
            for(int i=0;i<v.size();i++)
              {
                if(v[0]==ch1)
              {
                cout<<"\n+++++++++++++++++++++++++++++++++++++++++++ \n";
                cout<<"Name: "<<v[0]<<endl;
                cout<<"Gender: "<<v[1]<<endl;
                cout<<"City/town: "<<v[2]<<endl;
                cout<<"Blood Group: "<<v[3]<<endl;
                cout<<"Age: "<<v[4]<<endl;
                cout<<"Phone number: "<<v[5]<<endl;
                cout<<"LoginID: "<<v[6]<<endl;
                ctr++;
                break;
              }
            }
        }
        if(ctr==0)
        cout<<"\nStaff with no such name exists!";
        else
        cout<<"\nSuccessfully displayed "<<ctr<<" staffs.";

      }

      if(j==2)
      {
        ctr=0;
        ifstream x("staff.csv");
        string s;
        while (std::getline(x, s)) {
            std::vector<string> v;
            split(s,v,',');
            for(int i=0;i<v.size();i++)
              {
                if(v[2]==ch1)
              {
                cout<<"\n+++++++++++++++++++++++++++++++++++++++++++ \n";
                cout<<"Name: "<<v[0]<<endl;
                cout<<"Gender: "<<v[1]<<endl;
                cout<<"City/town: "<<v[2]<<endl;
                cout<<"Blood Group: "<<v[3]<<endl;
                cout<<"Age: "<<v[4]<<endl;
                cout<<"Phone number: "<<v[5]<<endl;
                cout<<"LoginID: "<<v[6]<<endl;
                ctr++;
                break;
              }
            }
        }
        if(ctr==0)
        cout<<"\nNo staff in such city found.";
        else
        cout<<"\nSuccessfully displayed "<<ctr<<" staffs.";
      }

      if(j==3)
      {
        ctr=0;
        ifstream x("staff.csv");
        string s;
        while (std::getline(x, s)) {
            std::vector<string> v;
            split(s,v,',');
            for(int i=0;i<v.size();i++)
              {
                if(v[3]==ch1)
              {
                cout<<"\n+++++++++++++++++++++++++++++++++++++++++++ \n";
                cout<<"Name: "<<v[0]<<endl;
                cout<<"Gender: "<<v[1]<<endl;
                cout<<"City/town: "<<v[2]<<endl;
                cout<<"Blood Group: "<<v[3]<<endl;
                cout<<"Age: "<<v[4]<<endl;
                cout<<"Phone number: "<<v[5]<<endl;
                cout<<"LoginID: "<<v[6]<<endl;
                ctr++;
                break;
              }
            }
        }
        if(ctr==0)
        cout<<"\nNo staff with such blood group found.";
        else
        cout<<"\nSuccessfully displayed "<<ctr<<" staffs.";
      }

    }

    if(ch=="citizen")
    {
      if(j==2)
      {
        ctr=0;
        ifstream x("citizen.csv");
        string s;
        while (std::getline(x, s)) {
            std::vector<string> v;
            split(s,v,',');
            for(int i=0;i<v.size();i++)
              {
                if(v[2]==ch1)
              {
                cout<<"\n+++++++++++++++++++++++++++++++++++++++++++ \n";
                cout<<"Name: "<<v[0]<<endl;
                cout<<"Gender: "<<v[1]<<endl;
                cout<<"City/town: "<<v[2]<<endl;
                cout<<"Blood Group: "<<v[3]<<endl;
                cout<<"Age: "<<v[4]<<endl;
                cout<<"Phone number: "<<v[5]<<endl;
                ctr++;
                break;
              }
            }
        }
        if(ctr==0)
        cout<<"\n No donor in such city found.";
        else
        cout<<"\n Successfully displayed "<<ctr<<" donors.";
      }

      if(j==3)
      {
        ctr=0;
        ifstream x("citizen.csv");
        string s;
        while (std::getline(x, s)) {
            std::vector<string> v;
            split(s,v,',');
            for(int i=0;i<v.size();i++)
              {
                if(v[3]==ch1)
              {
                cout<<"\n+++++++++++++++++++++++++++++++++++++++++++ \n";
                cout<<"Name: "<<v[0]<<endl;
                cout<<"Gender: "<<v[1]<<endl;
                cout<<"City/town: "<<v[2]<<endl;
                cout<<"Blood Group: "<<v[3]<<endl;
                cout<<"Age: "<<v[4]<<endl;
                cout<<"Phone number: "<<v[5]<<endl;
                ctr++;
                break;
              }
            }
        }
        if(ctr==0)
        cout<<"\nNo donor with such blood group found.";
        else
        cout<<"\nSuccessfully displayed "<<ctr<<" donors.";
      }
    }
  }



void readfile(string ch,string ch1, string ch2)//used to search on the basis of blood group and city and here ch=status ch1=blood and ch2==city
{
  int ctr;
  if(ch=="admin")
  {
    ctr=0;
    ifstream x("admin.csv");
    string s;
    while (std::getline(x, s)) {
        std::vector<string> v;
        split(s,v,',');
        for(int i=0;i<v.size();i++)
          {
            if(v[3]==ch1 && v[2]==ch2)
          {
            cout<<"\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
            cout<<"Name: "<<v[0]<<endl;
            cout<<"Gender: "<<v[1]<<endl;
            cout<<"City/town: "<<v[2]<<endl;
            cout<<"Blood Group: "<<v[3]<<endl;
            cout<<"Age: "<<v[4]<<endl;
            cout<<"Phone number: "<<v[5]<<endl;
            cout<<"LoginID: "<<v[6]<<endl;
            ctr++;
            break;
          }
          }
    }
    if(ctr==0)
    cout<<"\nAdministrators with no such details exists!";
    else
    cout<<"\nSuccessfully displayed "<<ctr<<" Administrators.";
  }

  if(ch=="staff")
  {ctr=0;
    ifstream x("staff.csv");
    string s;
    while (std::getline(x, s)) {
        std::vector<string> v;
        split(s,v,',');
        for(int i=0;i<v.size();i++)
          {
            if(v[3]==ch1 && v[2]==ch2)
          {
            cout<<"\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
            cout<<"result no.:"<<ctr+1<<endl;
            cout<<"Name: "<<v[0]<<endl;
            cout<<"Gender: "<<v[1]<<endl;
            cout<<"City/town: "<<v[2]<<endl;
            cout<<"Blood Group: "<<v[3]<<endl;
            cout<<"Age: "<<v[4]<<endl;
            cout<<"Phone number: "<<v[5]<<endl;
            cout<<"LoginID: "<<v[6]<<endl;
            std::cout << "Password: ***********" << '\n';
            ctr++;
            break;
          }
          }
    }
    if(ctr==0)
    cout<<"\nStaff Members with no such details exists!";
    else
    cout<<"\nSuccessfully displayed "<<ctr<<" Staff Members.";
  }
  if(ch=="citizen")
  {ctr=0;
      ifstream x("citizen.csv");
      string s;
      while (std::getline(x, s)) {
          std::vector<string> v;
          split(s,v,',');
          for(int i=0;i<v.size();i++)
            {
              if(v[3]==ch1 && v[2]==ch2)
            {
              cout<<"\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
              cout<<"result no.:"<<ctr+1<<endl;
              cout<<"Name: "<<v[0]<<endl;
              cout<<"Gender: "<<v[1]<<endl;
              cout<<"City/town: "<<v[2]<<endl;
              cout<<"Blood Group: "<<v[3]<<endl;
              cout<<"Age: "<<v[4]<<endl;
              cout<<"Phone number: "<<v[5]<<endl;
              ctr++;
              break;
            }
            }
      }
      if(ctr==0)
      cout<<"\nDonor with no such details exists!";
      else
      cout<<"\nSuccessfully displayed "<<ctr<<" Donors.";
  }
}


//*********************main() function****************************************
int main()
{
  int flag;
  Donor_details d;
  user *obj;
  int j,m;
cout<<"\n \t\t\t\t\t ******BLOOD GROUP DATABASE******";
cout<<"\n\n\n \t\t\t\t ******WELCOME******";
cout<<"\n Type of user";
cout<<"\n\n \t\t 1. Administrator \t\t 2. Staff member \t\t 3.Citizen";
cout<<"\n Enter your status: ";
int k;
cin>>k;


switch (k) {
  case 1: getchar();
          obj=new Admin;
          cout<<"\n \t\t\t\t LOGIN";
          m=obj->check_login("admin");
          flag=0;

          if(m==1)
          {

          cout<<"\n \t\t\t\t\t*****************WELCOME ADMINISTRATOR*****************";
          do {
          cout<<"\n Tasks Available";
          cout<<"\n 1. ADD A NEW ACCOUNT";
        //  cout<<"\n 2. EDIT AN ACCOUNT";
          cout<<"\n 2. DELETE AN ACCOUNT";
          cout<<"\n 3. SEARCH ACCOUNT(S)";
          cout<<"\n Enter your choice: ";
          cin>>j;


          switch (j) {
            case 1: {obj->putdata();}break;
            //case 2: obj->edit_acc();break;
            case 2: obj->deletedata();break;//used to delete entry
            case 3: obj->getdata();break;
          }
          cout<<"\n Do you want to perform more tasks?";
          cout<<" Press 1 for YES , 0 for NO: ";
          cin>>flag;
        }while(flag==1);

        }
          break;
  case 2: getchar();
          obj=new Staff;
          cout<<"\n \t\t\t\t LOGIN";
          flag=0;
          if(obj->check_login("staff")==1)
          {

        cout<<"\n \t\t\t\t\t*****************WELCOME STAFF MEMBER*****************";
        do{
        cout<<"\n Tasks Available";
        cout<<"\n 1. ADD A DONOR";
        cout<<"\n 2. SEARCH ACCOUNT(S)";
        cout<<"\n Enter your choice: ";
        cin>>j;
        switch (j) {
          case 1: obj->putdata();break;
          case 2: obj->getdata();break;

        }
        cout<<"\n Do you want to perform more tasks?";
        cout<<" Press 1 for YES , 0 for NO: ";
        cin>>flag;
      }while(flag==1);
      }
          break;
  case 3: obj=new citizen;
        flag=0;

        cout<<"\n \t\t\t\t\t*****************WELCOME USER*****************";
        do{
        cout<<"\n Tasks Available";
        cout<<"\n 1. REGISTER YOURSELF AS A DONOR";
        cout<<"\n 2. SEARCH DONOR(S)";
        cout<<"\n Enter your choice: ";
        cin>>j;
        switch (j) {
          case 1: putdata1(d);break; //obj->putdata();
          case 2: obj->getdata();break;
          }
          cout<<"\n Do you want to perform more tasks?";
          cout<<" Press 1 for YES , 0 for NO: ";
          cin>>flag;
        }while(flag==1);

          break;
  default: cout<<"\n Invalid choice";

}

return 0;
}

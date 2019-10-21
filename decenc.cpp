#include<bits/stdc++.h>

using namespace std;

void texttonumber(int);
void numbertotext(int);

char riteversion[6]="v4.01";

int modulusfind(int nos)
{
	if(nos<0)
   {
   	nos*=-1;
   }
   return nos;
}
//Forms the Diffie Hellman Keygen
int dhm_keygen()
{

   int usernos,silverkey,p,g,goldenkey;
   std::cout<<"Do you have your partner's security number and security passkey?\nEnter 1 for no and 0 for yes.";
   int choice1;
   cin>>choice1;
   do
   {
   	if(choice1==1)
	   {
   	   std::cout<<"\nAlright, we'll generate one for you.";
      	g=rand()%5+4;
	      //This mechanism would find a prime number p
   	   int primenos[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
      	p=primenos[rand()%25];
	      std::cout<<"\nYour security number is: "<<p<<" and security passkey is "<<g;
   	}
	   else if(choice1==0)
   	{
      	std::cout<<"\nEnter security number:";
	   	cin>>p;
   	   std::cout<<"\nEnter security passkey:";
      	cin>>g;
	   }
   	else
	   {
      	cerr<<"\nERROR. Invalid Input";
      }
   }while((choice1!=1)&&(choice1!=0));
   usernos=rand()%7+4;
   silverkey=modulusfind(fmod(pow(g,usernos),p));
   std::cout<<"\n Your Silver Key is "<<silverkey;
   std::cout<<"\nShare these details with your counterpart.";
   std::cout<<"\nEnter your counterparts Silver Key?:";
   cin>>silverkey;
   goldenkey=modulusfind(fmod(pow(silverkey,usernos),p));
   std::cout<<"\nOkay, we're set for encryption/decryption.";
   return(goldenkey);
}

// Main begins
int main()
{
  char ch,repeat='y';int goldenkey;
  std::cout<<"\nCrypto "<<riteversion<<" by NK7";
  std::cout<<"\nThis is a cryptograph program. Before you encrypt your message, ";
  goldenkey=dhm_keygen();
  do
  {

      std::cout<<"\nEnter:-";
      std::cout<<"\n \t 1 if you want to convert number to text.";
      std::cout<<"\n \t 2 if you want to convert text into number.\n";
  		cin>>ch;
     	if(ch==50)
     	{
        texttonumber(goldenkey);
     	}
    	else if(ch==49)
     	{
          numbertotext(goldenkey);
      }
      else
      {
      	cerr<<"\nError in input";
 //        for(long int wait=0;wait<99999999;wait++);
   //     	goto redo;
      }
      std::cout<<"\n To copy the output:";
      std::cout<<"\n1. Press Ctrl-M on your keyboard";
      std::cout<<"\n2. Select the output.";
      std::cout<<"\n3. Press the Enter key. Your output is pasted on the clipboard. ";
      std::cout<<"\n4. For speedy copy-and-pasting, please check the QuickEdit box in the Properties of this window.\nThe Properties section can be accessed by right clicking the title bar, and clicking Properties menu.";
      std::cout<<"\n\n\n\nNow, do you wish to repeat?";
      std::cout<<"\nEnter Y for yes and anything else if you want to quit:- \n";
      cin>>repeat;
  //   	redo:
     	}while((repeat=='y')||(repeat=='Y'));
  std::cout<<"\nTERMINATING.Version ";
  puts(riteversion);
  }

//Text to Number
void texttonumber(int goldenkey)
{
  	int output;
  	char input[100];

	std::cout<<"\nText to number. Sweet.";
	std::cout<<"\nEnter your text (max 100 characters) - \n";
  cin.ignore();
cin.getline(input, sizeof(input));
   int randomnos,addingfactor;
   randomnos=rand()%1000;
   addingfactor=randomnos+100;
   
  	std::cout<<"\nOUTPUT \n--\n";
 	for(int i=0;input[i]!='\0';i++)
 	{
		output=input[i]+(pow(-1,i)*2*i);
    	std::cout<<(output+addingfactor)<<".";
  	}

   addingfactor+=(goldenkey);
	std::cout<<"\b."<<(addingfactor-7)<<"."<<riteversion[1]<<"\n--";
	return;
}
//Number to Text
void numbertotext(int goldenkey)
{
	char input2[500];
  	int i,num[100];
  	std::cout<<"\nNumber to text. Sweet.";
   std::cout<<"\nEnter your number here:- \n";
   error1:
     cin.ignore();
cin.getline(input2, sizeof(input2));

     std::cout << "\n";
     for (i = 0; input2[i] != '\0'; i++)
     {
       if (!isdigit(input2[i]))
       {
         if (input2[i] != '.')
         {
         	cerr<<"\nThat was an error there.";
            goto error1;
         }
     }
   }
  	for(i=0;i<100;i++)                         //Resetting all values of num[i] to 0
  	{
  		num[i]='\0';
  	}
  	int k=0;
  	for(i=0;input2[i]!='\0';i++)
  	{
     if(input2[i]=='.')
  	  {
     		++k;
     }
     else
     	{
     		num[k]=(num[k]*10)+input2[i]-48; //48 is to convert the decimal "6" into human 6.
   	   //std::cout<<"\n num["<<k<<"]="<<num[k]<<endl;
     	}
  	}

  std::cout<<"\nOUTPUT\n--\n";
  int subtractingfactor;
  for(i=0;num[i]!=0;i++)
  {
  		if((num[i+2]==0)&&(num[i+1]!=0))
      {
         subtractingfactor=num[i]+7;
      }
   }

  //std::cout<<"\ntsum="<<goldenkey;
  subtractingfactor-=(goldenkey);
  //std::cout<<"\nSubtracting Factor after goldenkey= "<<subtractingfactor<<"\n";
  for(int k=0;num[k+2]!=0;++k)
  {

     	char chara;
  		chara=num[k]-subtractingfactor-(pow(-1,k)*2*k);
  		std::cout<<chara;
  }
  	std::cout<<"\n--";
	return;
}
#include"bits/stdc++.h"

using namespace std;

int main(int argc, char** argv)
{
	// PlayFair key
	char key[][5] = { 'l', 'g', 'd', 'b', 'a',
			  'q', 'm', 'h', 'e', 'c',
			  'u', 'r', 'n', 'i', 'f',
			  'x', 'v', 's', 'o', 'k',
			  'z', 'y', 'w', 't', 'p' };

	string message;
	
	cout<<"Enter your message : "<<endl;
	getline(cin, message);

	cout<<endl<<"Encrypting.."<<endl;

	int i, len = message.size();

	// to replace every 'j' with 'i' as there is no 'j' in our PlayFair key
	for(i=0;i<len;i++)
	{
		if(message[i] == 'j')
		{
			message[i] = 'i';
		}
	}

	// flag to save if there are pairs of characters that are the same
	int q = 0;
	for(i=0;i<len;i=i+2)
	{
		// checking if the constituents of the pair are same
		if(message[i] == message[i+1])
		{
			// setting the flag
			q = 1;
			// inserting a bogus character i.e 'x' between such pairs of characters and shifting the corresponding characters to the right
			for(int k=len-1;k>=i+1;k--)
			{
				message[k+1] = message[k];
			}
			message[i+1] = 'x';
		}
	}
	if(q!=0)
	{
		len += q;
	}
	if(len%2!=0)	// making sure the final length of the message to be encrypted is even by inserting bogus character at the end
	{
		message[len] = 'x';
		len++;
	}

	int j, k, m;
	string ciphertext;	
	int flag = 0, f = 0;

	// to work with the consecutive pairs of characters
	pair<char, char> pr;
	
	for(i=0;i<len;i=i+2)
	{
		flag = 0;
		pr.first = message[i];
		pr.second = message[i+1];

		for(j=0;j<5;j++)
		{
			f = 0;
			for(k=0;k<5;k++)
			{	
				if(pr.first == key[j][k])
				{
					f = 1;
					for(m=0;m<5;m++)
					{
						if(pr.second == key[j][m])
						{
							if(k!=4 && m!=4)
							{
								ciphertext[i] = key[j][k+1];
								ciphertext[i+1] = key[j][m+1];
							}
							else if(k==4 && m<4)
							{
								ciphertext[i] = key[j][0];
                                                                ciphertext[i+1] = key[j][m+1];
							}
							else if(k<4 && m==4)
							{
								ciphertext[i] = key[j][k+1];
                                                                ciphertext[i+1] = key[j][0];
							}
							
							flag = 1;
							break;
						}
					}
					
				}
			}
			if(f==1)
			{
				break;
			}

		}
		if(flag==1)
		{
			continue;
		}

		for(j=0;j<5;j++)
		{
			f = 0;
			for(k=0;k<5;k++)
			{
				if(pr.first == key[k][j])
                                {
					f = 1;
                                        for(m=0;m<5;m++)
                                        {
                                                if(pr.second == key[m][j])
                                                {
                                                        if(k!=4 && m!=4)
                                                        {
                                                                ciphertext[i] = key[k+1][j];
                                                                ciphertext[i+1] = key[m+1][j];
                                                        }
                                                        else if(k==4 && m<4)
                                                        {
                                                                ciphertext[i] = key[0][j];
                                                                ciphertext[i+1] = key[m+1][j];
                                                        }
                                                        else if(k<4 && m==4)
                                                        {
                                                                ciphertext[i] = key[k+1][j];
                                                                ciphertext[i+1] = key[0][j];
                                                        }

                                                        flag = 2;
                                                        break;
                                                }
                                        }
                                }
			}
			if(f==1)
			{
				break;
			}
		}
		if(flag==2)
		{		
			continue;
		}
		
		int r1, r2, c1, c2;

		for(j=0;j<5;j++)
		{
			for(k=0;k<5;k++)
			{
				if(pr.first == key[j][k])
				{
					r1 = j;
					c2 = k;
				}
				if(pr.second == key[j][k])
				{
					r2 = j;
					c1 = k;
				}
			}
		}
		
		ciphertext[i] = key[r1][c1];
		ciphertext[i+1] = key[r2][c2];
	}

	int v;
	cout<<endl<<"Encrypted message :"<<endl;
	for(i=0;i<len;i++)
	{
		v = int(ciphertext[i]) - 32;
		cout<<char(v);
	}
	cout<<endl;

	return 0;
}	

#include"bits/stdc++.h"

using namespace std;

pair<char, pair<char, int> > z[26];

string z26loc = "/home/amb/code/nslab/a1/z26Char";
int z26star[] = { 1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};

int main(int argc, char** argv)
{
	char delim = ' ';
	fstream z26load;

	z26load.open(z26loc);

	string line;
	int i = 0;

	string message;
	int key1, key2;

	cout<<"Enter your message :"<<endl;
	getline(cin, message);

	cout<<"Enter the first key value in z26* : "<<endl;
	cin>>key1;

	int flag = 0;
	for(int l=0;l<12;l++)
	{
		if(key1==z26star[l])
		{
			flag = 1;
			break;
		}
	}

	if(flag==0)
	{
		cout<<"Enter a valid symmetric key value."<<endl;
		return 0;
	}

	cout<<"Enter the second key value in z26 : "<<endl;
        cin>>key2;

	cout<<endl<<"Encrypting.."<<endl;

	while(getline(z26load, line))
	{
		string lowercase, uppercase, val;

		stringstream ss(line);

		getline(ss, lowercase, delim);
		getline(ss, uppercase, delim);	
		getline(ss, val);

		z[i].first = lowercase[0];
		z[i].second.first = uppercase[0];
		z[i].second.second = atoi(val.c_str());
		i++;		
	}

	int len = message.size(), k;
	string ciphertext;

	for(k=0;k<len;k++)
	{
		if(message[k] == ' ')
		{
			ciphertext[k] = ' ';
			continue;
		}

		for(i=0;i<26;i++)
		{
			if(message[k] == z[i].first)
			{
				int c = (z[i].second.second * key1) % 26;
				c = (c + key2) % 26;
				for(int j=0;j<26;j++)
				{
					if(c == z[j].second.second)
					{
						ciphertext[k] = z[j].second.first;
					}
				}
			}
		}
	}

	cout<<endl<<"Encrypted message : "<<endl;
	for(k=0;k<len;k++)
	{
		cout<<ciphertext[k];
	}
	cout<<endl;

	return 0;
}

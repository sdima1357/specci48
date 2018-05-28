/**********************************
*  GE CT_HAIFA_GROUP
*  Samsonov Dima
*  Command line options parser.
*  See bottom of file for usage
************************************/
#ifndef __OPTIONS_H
#define __OPTIONS_H
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <stdio.h>

using namespace std;

#define MAX_STRING_SIZE 	0x100
#define TAB_SIZE 		20


static char *typeNames[]={"int","float","double","string","bool"};

const char* getTypename(int& val)  	{return typeNames[0];}
const char* getTypename(float& val)	{return typeNames[1];}
const char* getTypename(double& val)  	{return typeNames[2];}
const char* getTypename(string& val)    {return typeNames[3];}
const char* getTypename(bool& val)      {return typeNames[4];}

class COptions
{
   public:

	COptions(int pn,char*ps[]) : m_exename(ps[0])
	{
		for(int i=1;i<pn;i++) 
		{
			m_strings.push_back(string(ps[i]));
		} 
	}
	
	template<class T> void Parse(const char* optString,T & optVar,char*comment,T defaultval)
	{
		//~ char HelpString[MAX_STRING_SIZE];
		//~ for(int i=0;i<MAX_STRING_SIZE;i++)
		//~ {
			//~ HelpString[i] = 0;
		//~ }
		//~ memset(HelpString,0,MAX_STRING_SIZE);
		
		ostringstream ss;
		
		ss.setf(ios::left);
		
		ss	<<setw(TAB_SIZE)<<optString
			<<setw(TAB_SIZE)<<getTypename(optVar)
			<<setw(TAB_SIZE)<<comment
			<<setw(TAB_SIZE)<<defaultval;
		
		m_help.push_back(ss.str());
		
		vector<string>::iterator current= find(m_strings.begin(),m_strings.end(),string(optString));
		
		optVar =  defaultval;
		
		
		
		if(current!=m_strings.end())
		{
			if(current+1==m_strings.end()) 
				{
					m_error.push_back(string("\nUncomplete parm error:"));
					m_error.push_back(*current);
					m_strings.erase(current,current+1);	
					m_error.push_back(string("\n"));
					return ;
				}	
			if(!Read(*(current+1),optVar))
			{			
				m_error.push_back(string("\nRead argument error:"));
				m_error.push_back(*current);
				m_error.push_back(*(current+1));
				m_error.push_back(string("\n"));
			}
			m_strings.erase(current,current+2);	
		}
		
	}		
	
	template<class T> void Parse(const char* optString,T & optVar,char*comment)
	{
		//~ char HelpString[MAX_STRING_SIZE];
		//~ for(int i=0;i<MAX_STRING_SIZE;i++)
		//~ {
			//~ HelpString[i] = 0;
		//~ }
		
		//~ memset(HelpString,0,MAX_STRING_SIZE);
		
		ostringstream ss;
		
		ss.setf(ios::left);
		
		ss	<<setw(TAB_SIZE)<<optString
			<<setw(TAB_SIZE)<<getTypename(optVar)
			<<setw(TAB_SIZE)<<comment
			<<setw(TAB_SIZE)<<"No default";
		
		m_help.push_back(ss.str());
		
		vector<string>::iterator current= find(m_strings.begin(),m_strings.end(),string(optString));
		
		//optVar =  defaultval;
		
		
		
		if(current!=m_strings.end())
		{
			if(current+1==m_strings.end()) 
				{
					m_error.push_back(string("\nUncomplete parm error:"));
					m_error.push_back(*current);
					m_strings.erase(current,current+1);	
					m_error.push_back(string("\n"));
					return ;
				}	
			if(!Read(*(current+1),optVar))
			{			
				m_error.push_back(string("\nRead argument error:"));
				m_error.push_back(*current);
				m_error.push_back(*(current+1));
				m_error.push_back(string("\n"));
			}
			m_strings.erase(current,current+2);	
		}
		else
		{
			m_error.push_back(string("\nParameter must be defined:"));
			m_error.push_back(string(optString));
			m_error.push_back(string("\n"));
			
		}
		
	}		
	
	bool IsOk()
	{
		return !(m_strings.size()||m_error.size());
	}
	
	void Usage(char* Mess)
	{
		cerr<<"\n"<<Mess<<"\n";
		if(m_strings.size())
		{	
		 cerr<<"Unknow Parametr(s) : ";
		 copy(m_strings.begin(),m_strings.end(),ostream_iterator<string>(cerr," ")); 	
		 cerr<<"\n";
	        }
		if(m_error.size())
		{	
		 copy(m_error.begin(),m_error.end(),ostream_iterator<string>(cerr," ")); 	
		 cerr<<"\n";
	        }
	        
		cerr<<"\nUsage : ";
		cerr<<m_exename<<"\n";
		
		cerr.setf(ios::left);
		
		cerr	<<setw(TAB_SIZE)<<"Option String"
			<<setw(TAB_SIZE)<<"Type Of Argument"
			<<setw(TAB_SIZE)<<"Comment"
			<<setw(TAB_SIZE)<<"Default Value"
			<<"\n\n";
		
		copy(m_help.begin(),m_help.end(),ostream_iterator<string>(cerr," \n")); 	
		
	};
	
   private:	
        
	vector<string> m_strings;
        string 	       m_exename;
	vector<string> m_help;
	vector<string> m_error;
   private:	

	bool Read(string& str,float&optVar)
	{
		sscanf(str.c_str(),"%f",&optVar);	
		return true;
	}
	bool Read(string& str,double&optVar)
	{
		sscanf(str.c_str(),"%lf",&optVar);	
		return true;
	}
	bool Read(string& str,int&optVar)
	{
		sscanf(str.c_str(),"%d",&optVar);	
		return true;
	}
	bool Read(string& str,bool&optVar)
	{
		if(str=="on")  {optVar = true; return true;}
		if(str=="off") {optVar = false;return true;}
		if(str=="1")   {optVar = true; return true;}
		if(str=="0")   {optVar = false;return true;}
		return false;
	}
	bool Read(string& str,string&optVar)
	{
		optVar = str;
		return true;
	}
	
		
};

#ifdef __C_OPTIONS_TEST
void main(int  pn,char*ps[])
{
   COptions Options(pn,ps); 	
   
   float  ftest;	 
   int    itest;	
   string inputFile;	 
   string outputFile;	
   bool   btest;	 
	
   try 	{	
	Options.Parse("-fov"		,ftest		,"Fild Of View" 	,3.1f);
	Options.Parse("-in"		,inputFile	,"Input File Name");
	Options.Parse("-out"		,outputFile	,"Output File Name" 	,string("out.file"));
	Options.Parse("-numViews"	,itest	    	,"Number Of Views" 	,984);
	Options.Parse("-rf"		,btest	    	,"RingFix (on,off)" 	,true);
	}
   catch(...) 
   {
	Options.Usage("Catch error");exit(0);
   } 
   if(!Options.IsOk()){Options.Usage("Parse Error");exit(0);} 	
    	
}
#endif //C_OPTIONS_TEST

#endif //__OPTIONS_H

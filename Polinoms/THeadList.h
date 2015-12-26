#include "stdafx.h"
#include <iostream>
using namespace std;
template <class T>
class TLink
{
public:
	T value;
	TLink *pNext;
};
template <class T>
class THeadList
{
protected:
	TLink<T> *pHead, *pFirst, *pLast, *pCurr, *pPred, *pStop;
	int pos, len;
public:
	THeadList()
	{
		pHead = new TLink<T>;
		pStop = pHead;
		pHead->pNext=pStop;
		pFirst=NULL;pLast=NULL;pCurr=NULL;pPred=NULL;
		pos=-1; len=0;
	}
	~THeadList()
	{
		pCurr = pFirst;
		if (len!=0)
		{
			while (pCurr!=pStop)
			{
				pPred = pCurr;
				pCurr = pCurr->pNext;
				delete pPred;
			}
		}
		delete pHead;
	}
	void InsFirst (const T elem)
	{
		TLink<T> *tmp = new TLink<T>;
		tmp->value = elem;
		pHead->pNext=tmp;
		if(len == 0)
		{
			tmp->pNext=pStop;
			pFirst=pLast=tmp;
		}
		else
		{
			tmp->pNext=pFirst;
			pFirst = tmp;
		}
		len = len+1;
		pos++;
	}
	void DelFirst()
	{
		//if (len == 0) throw len;
		if (len!=0)
		{
			pHead->pNext=pFirst->pNext;
			delete pFirst;
			pFirst=pHead->pNext;
		    len--;
			pos--;
		}
	}
	void InsCurr(const T elem)
	{
		if (pCurr == pFirst) InsFirst(elem);
		else
		{
		TLink<T> *tmp = new TLink<T>;
		tmp->value = elem;
		pPred->pNext=tmp;
		tmp->pNext=pCurr;
		pCurr=tmp;
		len++;
		}
	}
	void DelCurr()
	{
		if (pCurr == pFirst) DelFirst();
		else
		{
			pPred->pNext=pCurr->pNext;
			delete pCurr;
			pCurr=pPred->pNext;
			len--;
		}
	}
	void InsLast( const T elem)
	{
		if (len ==0) {
			InsFirst(elem);
		}
		else
		{
		TLink<T> *tmp = new TLink<T>;
		tmp->value=elem;
		tmp->pNext=pStop;
		pLast->pNext=tmp;
		pLast = tmp;
		len++;
		}
	}
	void Reset()
	{
		pCurr = pFirst;
	}
	void Next()
	{
		pPred = pCurr;
		pCurr = pCurr->pNext;
	}
	bool IsEnd()
	{
		return pCurr == pStop;
	}
};




			

			
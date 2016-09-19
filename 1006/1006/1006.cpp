/*******************************************************************************
** Copyright (C), 	2016- , Zach Yeo.                                          *
** File name:		1006.cpp                                                   *
** Description:                                                                *
** Author:			Zhang Shize <zszv587@gmail.com>                            *
**-----------------------------------------------------------------------------*
** History:                                                                    *
** v1.0				2016-09-05					                               *
********************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int t[1000000 + 1];

int main(){

	int n;
	int now = 0;
	long long int max = 0;
	long long int sum = 0;
	long long int tem = 0;

	int i;
	int first_time = 0;
	int POSITIVE = 1;

	int zeroflag = 0;

	scanf ( "%d", &n );

	for ( i = 1; i <= n; i ++ ){
	
		scanf ( "%d", &now );
		t[i] = now;

		/*�����ж��Ƿ����������У���tem=0,����ǰһ������Ϊ0������£�����һ��������󣬲��Ƶ�max
		  ����0�������ͨ���洢�����������ݣ��������ѭ��һ���ж����е���������ǰ��Ϊ0��������
		  ����������*/
		tem = sum;

		sum += now;

		if ( sum < 0 ){
		
			sum = 0;

		}
		
		if ( sum > max && tem != 0 ){
		
			max = sum;
		
		}

	}

	int j;
	j = 1;

	for ( j = 2; j <= n - 1; j ++ ){
		
		if ( t[j] > 0 && t[j - 1] <= 0 && t[j + 1] <= 0 ){
			
			if ( t[j - 1] < t[j + 1] ){
				
				if ( t[j] + t[j + 1] > max ){
				
					max = t[j] + t[j + 1];
				
				}
				
			}

			else {
			
				if ( t[j] + t[j - 1] > max ){
				
					max = t[j] + t[j - 1];
				
				}

			}
			
		}
		
	}

	if ( t[1] + t[2] > max ){
	
		max = t[1] + t[2];

	}
	if ( t[n - 1] + t[n] > max ){
	
		max = t[n] + t[n - 1];
	
	}


	if ( max == 0 ){
	
		printf ( "Game Over\n" );
	
	}
	else {
	
		printf ( "%d\n", max );
	
	}


	return 0;
	
}

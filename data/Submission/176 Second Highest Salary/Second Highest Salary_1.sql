#-*- coding:utf-8 -*-
#Generated by the Fetch-Leetcode project on the Github
#https://github.com/CJHMPower/Fetch-Leetcode/ 

#176 Second Highest Salary
#https://leetcode.com//problems/second-highest-salary/description/
#Fetched at 2018-07-24
#Submitted 1 month, 2 weeks ago
#Runtime: 149 ms
#This solution defeats 67.07% mysql solutions

# Write your MySQL query statement below
SELECT MAX(Salary) AS SecondHighestSalary FROM Employee  WHERE Salary NOT IN (SELECT MAX(Salary) FROM Employee)
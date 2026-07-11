# Write your MySQL query statement below

select firstName,lastName,city,state
from Person p1 left join
Address a2 on p1.personId=a2.personId;
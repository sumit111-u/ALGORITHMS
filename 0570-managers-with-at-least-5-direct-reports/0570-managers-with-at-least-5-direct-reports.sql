# Write your MySQL query statement below

select e1.name

from Employee e1
join Employee e2
on e1.id=e2.managerid
group by e2.managerid
having count(e2.managerid)>=5;
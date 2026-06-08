# Write your MySQL query statement below

select e1.name,b.bonus
from Employee as e1
 left join Bonus as b on e1.empId=b.empId where bonus<1000 or bonus is null;
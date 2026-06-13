# Write your MySQL query statement below
 select r.contest_id ,  ROUND(COUNT(*) * 100.0 / (SELECT COUNT(*) FROM Users), 2) AS percentage

 from Register r
 group by contest_id
 order by percentage desc,
  contest_id ;

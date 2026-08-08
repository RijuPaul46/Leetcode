# Write your MySQL query statement below
SELECT distinct(l1.num) as ConsecutiveNums
from Logs as l1 join 
Logs as l2 on l2.id=l1.id+1
join Logs as l3 on 
l3.id=l1.id+2
where l1.num=l2.num AND l3.num=l1.num
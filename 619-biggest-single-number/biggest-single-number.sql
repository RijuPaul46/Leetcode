# Write your MySQL query statement below
select IFNULL(
    (SELECT num 
from MyNumbers group by num 
having count(*)=1
ORDER BY NUM DESC 
LIMIT 1
    ),NULL   
)as num;

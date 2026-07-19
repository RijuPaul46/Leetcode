# Write your MySQL query statement below
SELECT e.name As Employee
from Employee as e left join Employee as f
on e.managerId=f.id
WHERE e.salary>f.salary;
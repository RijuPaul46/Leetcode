# Write your MySQL query statement below
select max(salary) as SecondHighestSalary from (
    select  
    salary,
    ROW_NUMBER() OVER (order by salary desc) as rank_no
    from (
        select distinct salary from employee
    )as e2
)as e1 
where
rank_no=2
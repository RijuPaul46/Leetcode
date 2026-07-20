# Write your MySQL query statement below
#first find all the red .. then remove them 
-- SELECT sp.name from 
-- SalesPerson as sp LEFT JOIN Orders as o
-- ON o.sales_id=sp.sales_id
-- LEFT JOIN Company c 
-- ON o.com_id=c.com_id
-- WHERE c.name is not null or c.name <> 'RED';
SELECT name from SalesPerson 
where name not in(
SELECT sp.name from 
SalesPerson as sp JOIN Orders as o
ON o.sales_id=sp.sales_id
JOIN Company c 
ON o.com_id=c.com_id
where c.name='RED'
);
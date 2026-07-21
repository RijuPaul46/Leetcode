# Write your MySQL query statement below
SELECT author_id as id from(
    SELECT * from Views 
    where author_id=viewer_id
) as temp
group by author_id 
order by author_id asc;
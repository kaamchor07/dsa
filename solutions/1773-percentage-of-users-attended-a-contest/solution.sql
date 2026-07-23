# Write your MySQL query statement below
SELECT contest_id,ROUND(
    100*COUNT(user_id)/(select count(*) from Users)
    ,2)  
    AS percentage
FROM Register 
GROUP BY contest_id
ORDER BY percentage DESC, contest_id ASC;

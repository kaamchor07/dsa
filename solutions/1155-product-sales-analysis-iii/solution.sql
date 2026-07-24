# Write your MySQL query statement below
SELECT product_id,year as first_year,quantity,price
FROM Sales
where (product_id,year) in (
    select product_id,MIN(year)
    from Sales
GROUP BY product_id);
 

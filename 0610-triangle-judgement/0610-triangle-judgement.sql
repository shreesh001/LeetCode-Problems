# Write your MySQL query statement below
# Write your MySQL query statement below
select *, 
       CASE
           WHEN x+y>z and y+z>x and z+x>y THEN 'Yes'
           ELSE 'No'
       END AS triangle
from triangle

# Write your MySQL query statement below
SELECT * FROM Cinema c
WHERE id % 2 = 1 AND description <> "boring"
ORDER BY rating DESC;
WITH AVG_SCORE AS (
    SELECT EMP_NO, AVG(SCORE) AS SCORE
        FROM HR_GRADE
            GROUP BY EMP_NO 
),
AVG_GRADE AS (
    SELECT EMP_NO, CASE
                    WHEN 96 <= SCORE THEN 'S'
                    WHEN 90 <= SCORE THEN 'A'
                    WHEN 80 <= SCORE THEN 'B'
                    ELSE 'C'
                    END AS GRADE, 
                    CASE
                    WHEN 96 <= SCORE THEN 20
                    WHEN 90 <= SCORE THEN 15
                    WHEN 80 <= SCORE THEN 10
                    ELSE 0
                    END AS BONUS
        FROM AVG_SCORE
)

SELECT E.EMP_NO, E.EMP_NAME, G.GRADE, E.SAL * G.BONUS / 100 AS BONUS
    FROM HR_EMPLOYEES E
    INNER JOIN AVG_GRADE G
    ON E.EMP_NO = G.EMP_NO
        ORDER BY EMP_NO
    

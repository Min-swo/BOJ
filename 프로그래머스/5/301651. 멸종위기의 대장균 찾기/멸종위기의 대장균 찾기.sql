WITH RECURSIVE rc AS (
    SELECT 
        ID,
        PARENT_ID,
        1 AS GENERATION
    FROM ECOLI_DATA
    WHERE PARENT_ID IS NULL

    UNION ALL

    SELECT 
        e.ID,
        e.PARENT_ID,
        rc.GENERATION + 1
    FROM ECOLI_DATA e
    JOIN rc ON e.PARENT_ID = rc.ID
)

SELECT COUNT(ID) AS COUNT, GENERATION FROM rc r
    WHERE NOT EXISTS (
                SELECT 1 
                FROM rc c 
                WHERE c.PARENT_ID = r.ID
            )
    GROUP BY GENERATION
    ORDER BY GENERATION;

WITH RECURSIVE GenerationTree AS (
    -- 1세대: 최초 개체 (PARENT_ID가 NULL)    
    SELECT 
        ID,
        CASE
            WHEN NOT EXISTS (select 1 from ECOLI_DATA e where e.PARENT_ID = e2.ID) THEN 1
            ELSE 0 
        END AS NO_CHILD,
        1 AS GENERATION
    FROM ECOLI_DATA e2
    WHERE PARENT_ID IS NULL

    UNION ALL

    -- 2세대 이상: 부모의 GENERATION + 1
    SELECT 
        e3.ID,
        CASE
            WHEN NOT EXISTS (select 1 from ECOLI_DATA e4 where e4.PARENT_ID = e3.ID) THEN 1
            ELSE 0 
        END AS NO_CHILD,
        gt.GENERATION + 1
    FROM ECOLI_DATA e3 JOIN GenerationTree gt 
        ON e3.PARENT_ID = gt.ID and gt.NO_CHILD = 0
)

SELECT SUM(NO_CHILD) AS COUNT, GENERATION
    FROM GenerationTree
        GROUP BY GENERATION
ORDER BY GENERATION;

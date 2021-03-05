class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        preaMap = { i: [] for i in range(numCourses)}
        for cours, prereq in prerequisites:
            preaMap[cours].append(prereq)
            
        visit = set()
        def dfs(crs):
            if crs in visit:
                return False
            if preaMap[crs] == []:
                return True
            
            visit.add(crs)
            for pre in preaMap[crs]:
                if not dfs(pre): return False
            visit.remove(crs)
            preaMap[crs] = []
            return True
        
        for c in range(numCourses):
            if not dfs(c): return False
        return True
        

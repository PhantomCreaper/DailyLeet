class Solution(object):
    def countStudents(self, students, sandwiches):
        """
        :type students: List[int]
        :type sandwiches: List[int]
        :rtype: int
        """
        students = deque(students)
        sandwich_index = 0
        no_match_rotations = 0

        while students and no_match_rotations < len(students):
            if students[0] == sandwiches[sandwich_index]:
                students.popleft()
                sandwich_index += 1
                no_match_rotations = 0
            else:
                students.rotate(-1)
                no_match_rotations += 1

        return len(students)
        

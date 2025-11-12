import React from 'react';
import Student from './Student.jsx';
function StudentList() {
    const students = [
        { id: 1, name: "Abhijith", age: 21, course: "MCA" },
        { id: 2, name: "Abhinav", age: 22, course: "MCA" },
        { id: 3, name: "Abhirami", age: 21, course: "MCA" },
        { id: 4, name: "Adish", age: 21, course: "MCA" }
    ];
    return (
        <div>
            {students.map((student) =>
                <Student
                    key={student.id}
                    name={student.name}
                    age={student.age}
                    course={student.course}
                />
            )}
        </div>
    );
}
export default StudentList;
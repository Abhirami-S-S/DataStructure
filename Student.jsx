import React from "react";
function Student({ name, age, course }) {
    return (
        <div>
            <h3>Name:{name}</h3>
            <p>Age:{age}</p>
            <p>Course:{course}</p>
        </div>
    );
}
export default Student;
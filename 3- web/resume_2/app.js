function loadPageContent(content) {
    document.getElementById('content').innerHTML = content;
}

page('/', function () {
    loadPageContent('<h2>Education</h2><p>ITMO University</p><p>Bachelors in Computer Science</p>');
});

page('/projects', function () {
    loadPageContent('<h2>Projects</h2><div class="project"><p>Coordinate Plane Analysis Web App | Java, Servlets, JSP, JavaScript</p><p>St. Petersburg, Russia</p><p>Sep. 2021 – Present</p><ul><li>Implemented an MVC architecture for point analysis on a coordinate plane using Java Servlets and JavaServer Pages (JSP)</li><li>Developed a dynamic JSP page with a user-friendly web form and real-time results visualization</li><li>Integrated JavaScript for client-side validation and interactive features</li><li>Deployed the application on WildFly, ensuring optimal configuration</li><li>Enabled dynamic updates to the coordinate plane image based on user input</li><li>Utilized HttpSession for tracking and displaying previous analysis results</li></ul></div>');
});

page();

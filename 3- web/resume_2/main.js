
console.log("Hello from main.js!");

document.addEventListener("DOMContentLoaded", function () {
    const urlParams = new URLSearchParams(window.location.search);
    const page = urlParams.get('page');

    if (page === 'projects') {
        const projectDetailsSection = document.getElementById('project-details');
        projectDetailsSection.innerHTML += "<p>Additional content for projects page.</p>";
    }
});
document.addEventListener('DOMContentLoaded', () => {
    let nightMode = localStorage.getItem('nightMode');

    if (nightMode === null) {
        nightMode = 'false';
    }

    applyNightMode(nightMode);

    document.getElementById('night-mode-toggle').addEventListener('click', () => {
        nightMode = (nightMode === 'true') ? 'false' : 'true';
        applyNightMode(nightMode);
        localStorage.setItem('nightMode', nightMode);
    });
});

function applyNightMode(nightMode) {
    document.body.classList.toggle("night-mode", nightMode === 'true');
}

document.addEventListener('DOMContentLoaded', () => {

    displayCurrentDateTime();

    setInterval(displayCurrentDateTime, 1000);
});

function displayCurrentDateTime() {
    const dateTimeContainer = document.getElementById('current-date-time');
    const now = new Date();
    const options = { weekday: 'long', year: 'numeric', month: 'long', day: 'numeric', hour: 'numeric', minute: 'numeric', second: 'numeric', timeZoneName: 'short' };
    const formattedDateTime = now.toLocaleDateString('en-US', options);

    dateTimeContainer.innerHTML = `<p>${formattedDateTime}</p>`;
}

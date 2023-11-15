// JavaScript to handle tab switching
document.getElementById('projects-tab').addEventListener('click', function () {
    showTab('projects-content');
});

document.getElementById('game-tab').addEventListener('click', function () {
    showTab('game-content');
});

document.getElementById('contact-tab').addEventListener('click', function () {
    showTab('contact-content');
});

function showTab(tabId) {
    const tabs = document.getElementsByClassName('tab-content');
    for (const tab of tabs) {
        tab.style.display = 'none';
    }
    document.getElementById(tabId).style.display = 'block';
}

// Show the default tab (e.g., Projects)
showTab('projects-content');
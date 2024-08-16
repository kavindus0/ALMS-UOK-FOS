document.addEventListener('DOMContentLoaded', () => {
    console.log('A/L Management System Loaded');

    // Example of adding functionality
    const navLinks = document.querySelectorAll('nav a');
    navLinks.forEach(link => {
        link.addEventListener('click', (event) => {
            event.preventDefault();
            const sectionId = link.getAttribute('href').substring(1);
            const section = document.getElementById(sectionId);
            if (section) {
                window.scrollTo({
                    top: section.offsetTop,
                    behavior: 'smooth'
                });
            }
        });
    });
});


// Function to fetch and insert text file content into HTML
function insertTextFileContent(url, targetElementId) {
    fetch(url)
        .then(response => response.text())
        .then(text => {
            // Split the text content into lines
            const lines = text.split('\n');

            // Get the target element where the content will be inserted
            const targetElement = document.getElementById(targetElementId);

            // Clear the target element's content
            targetElement.innerHTML = '';

            // Process each line
            lines.forEach(line => {
                // Create a new paragraph element for each line
                const p = document.createElement('p');
                p.textContent = line;

                // Append the paragraph to the target element
                targetElement.appendChild(p);
            });
        })
        .catch(error => console.error('Error fetching the text file:', error));
}


insertTextFileContent('../logtrack.txt', 'p');
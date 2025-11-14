const fileInput = document.getElementById("fileInput") as HTMLInputElement;
const uploadedImage = document.getElementById("uploadedImage") as HTMLImageElement;
const canvas = document.getElementById("canvasOutput") as HTMLCanvasElement;
const loader = document.getElementById("loader") as HTMLElement;

const ctx = canvas.getContext("2d")!;

// Handle PNG upload
fileInput.addEventListener("change", async () => {
    const file = fileInput.files?.[0];
    if (!file) return;

    loader.style.display = "block";

    const url = URL.createObjectURL(file);
    uploadedImage.src = url;

    uploadedImage.onload = () => {
        canvas.width = uploadedImage.width;
        canvas.height = uploadedImage.height;

        ctx.drawImage(uploadedImage, 0, 0);

        loader.style.display = "none";
    };
});



#include "SortVisualizer.h"

sort::SortVisualizer::SortVisualizer(QWidget* parent) :
	QOpenGLWidget(parent), qRender(), collumnObject(), timer(), completion() { }

void sort::SortVisualizer::initializeGL() {
	initializeOpenGLFunctions();

	glm::mat4 projection{ glm::ortho(0.0f, (float)this->size().width(), 0.0f, (float)this->size().height(), -1.0f, 1.0f) };
	ResourceManager::LoadShader("source/SortVisualizer GUI/SortVisualizer/Shaders/quadShader.vert", "source/SortVisualizer GUI/SortVisualizer/Shaders/quadShader.frag", "quadShader");
	ResourceManager::GetShader("quadShader")->use();
	ResourceManager::GetShader("quadShader")->setMat4("projection", projection);

	qRender = new quadRenderer();
	
	timer = new QElapsedTimer();
	timer->start();
}

void sort::SortVisualizer::Render(uint32_t first_iter, uint32_t second_iter) {
	this->first_iter = first_iter;
	this->second_iter = second_iter;
	this->completion = false;

	this->timer->start();
	while (timer->elapsed() <= this->speed)
		repaint();
}

void sort::SortVisualizer::Render() {
	completion = true;

	repaint();
}

void sort::SortVisualizer::paintGL() {
	if (this->collumnObject) {
		if (!this->completion)
			this->RenderSort();
		else
			this->RenderCompletedSort();
	}
}

void sort::SortVisualizer::resizeGL(int width, int height) {
	glViewport(0, 0, width, height);
	glm::mat4 projection{ glm::ortho(0.0f, (float)width, 0.0f, (float)height, -1.0f, 1.0f) };
	ResourceManager::GetShader("quadShader")->use();
	ResourceManager::GetShader("quadShader")->setMat4("projection", projection);
}

void sort::SortVisualizer::SetSpeed(uint32_t speed) {
	this->speed = speed;
}

void sort::SortVisualizer::SetCollumnObject(CollumnArrayObject* object) {
	this->collumnObject = object;
	this->collumnObject->SetRender(this->qRender);
	this->collumnObject->SetShader(ResourceManager::GetShader("quadShader"));
}

void sort::SortVisualizer::RenderSort() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	this->collumnObject->DrawCollumns(this->size().width(), this->size().height(), this->first_iter, this->second_iter);
}

void sort::SortVisualizer::RenderCompletedSort() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	this->collumnObject->DrawCompleteCollumns(this->size().width(), this->size().height());
}


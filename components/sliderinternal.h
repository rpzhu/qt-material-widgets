#ifndef SLIDERINTERNAL_H
#define SLIDERINTERNAL_H

#include <QWidget>
#include <QStateMachine>

class Slider;
class SliderThumb;
class SliderTrack;

class SliderStateMachine : public QStateMachine
{
    Q_OBJECT

public:
    SliderStateMachine(Slider *parent, SliderThumb *thumb, SliderTrack *track);
    ~SliderStateMachine();

signals:
    void changedToMinimum();
    void changedFromMinimum();
    void sliderEnabled();
    void sliderDisabled();
    void noFocusMouseEnter();
    void noFocusMouseLeave();

private:
    Q_DISABLE_COPY(SliderStateMachine)
};

class SliderThumb : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(qreal diameter WRITE setDiameter READ diameter)
    Q_PROPERTY(qreal borderWidth WRITE setBorderWidth READ borderWidth)
    Q_PROPERTY(QColor fillColor WRITE setFillColor READ fillColor)
    Q_PROPERTY(QColor minFillColor WRITE setMinFillColor READ minFillColor)
    Q_PROPERTY(qreal haloSize WRITE setHaloSize READ haloSize)
    Q_PROPERTY(QColor haloColor WRITE setHaloColor READ haloColor)

public:
    explicit SliderThumb(Slider *slider);
    ~SliderThumb();

    inline void setDiameter(qreal diameter)
    {
        _diameter = diameter;
        update();
    }

    inline qreal diameter() const
    {
        return _diameter;
    }

    inline void setBorderWidth(qreal width)
    {
        _borderWidth = width;
        update();
    }

    inline qreal borderWidth() const
    {
        return _borderWidth;
    }

    inline void setFillColor(const QColor &color)
    {
        _fillColor = color;
        update();
    }

    inline QColor fillColor() const
    {
        return _fillColor;
    }

    inline void setMinFillColor(const QColor &color)
    {
        _minFillColor = color;
        update();
    }

    inline QColor minFillColor() const
    {
        return _minFillColor;
    }

    inline void setHaloSize(qreal size)
    {
        _haloSize = size;
        update();
    }

    inline qreal haloSize() const
    {
        return _haloSize;
    }

    inline void setHaloColor(const QColor &color)
    {
        _haloColor = color;
        update();
    }

    inline QColor haloColor() const
    {
        return _haloColor;
    }

protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    Q_DISABLE_COPY(SliderThumb)

    const Slider *const slider;
    qreal  _diameter;
    qreal  _borderWidth;
    qreal  _haloSize;
    QColor _fillColor;
    QColor _minFillColor;
    QColor _haloColor;
};

class SliderTrack : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QColor fillColor WRITE setFillColor READ fillColor)
    Q_PROPERTY(int trackWidth WRITE setTrackWidth READ trackWidth)

public:
    explicit SliderTrack(Slider *slider);
    ~SliderTrack();

    inline void setFillColor(const QColor &color)
    {
        _fillColor = color;
        update();
    }

    inline QColor fillColor() const
    {
        return _fillColor;
    }

    void setTrackWidth(int width)
    {
        _width = width;
        update();
    }

    int trackWidth() const
    {
        return _width;
    }

protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    Q_DISABLE_COPY(SliderTrack)

    const Slider *const slider;
    QColor _fillColor;
    int    _width;
};

#endif // SLIDERINTERNAL_H
